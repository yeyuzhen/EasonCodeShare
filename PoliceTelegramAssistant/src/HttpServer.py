#!/usr/bin/env python
#coding=utf-8


from BaseHTTPServer import BaseHTTPRequestHandler,HTTPServer
from SocketServer import ThreadingMixIn
import threading
import argparse
import re
import cgi
import json
from Model import DBConnect
from Utility import Utility
 
class HTTPRequestHandler(BaseHTTPRequestHandler):
 
    def do_POST(self):
        if None != re.search('/api/add_telegram/*', self.path):  # 接收到电报信息请求
            ctype, pdict = cgi.parse_header(self.headers.getheader('content-type'))
            if ctype == 'application/json':
                length = int(self.headers.getheader('content-length'))
                jsonData = cgi.parse_qs(self.rfile.read(length), keep_blank_values=1)
                # 把 data 的值解析出来
                encodedJson = json.dumps(jsonData) # THINK 需要这步吗？
                decodeJson = json.loads(encodedJson)
                # 把 JSON 串转成 Python Dict
                dictTelegramInfo = json.loads(decodeJson['data'][0])
                # 把数据写入数据库
                Utility.SaveInTelegramInfo(dictTelegramInfo)
                
 
                self.send_response(200)
                self.end_headers()
                self.wfile.write('{"result":"success"}')
                self.wfile.close()
        elif None != re.search('/api/check_address/*', self.path):  # 接收到地址检查请求
            ctype, pdict = cgi.parse_header(self.headers.getheader('content-type'))
            if ctype == 'application/json':
                length = int(self.headers.getheader('content-length'))
                jsonData = cgi.parse_qs(self.rfile.read(length), keep_blank_values=1)
                # 把 data 的值解析出来
                encodedJson = json.dumps(jsonData)
                decodeJson = json.loads(encodedJson)

                print 'check_address'
                print decodeJson['data'][0]

                self.send_response(200)
                self.end_headers()

                # 本地信息和收到的地址信息比较
                if self.IsMyAddress(decodeJson['data'][0]):
                    self.wfile.write('{"result":"success", "ip":"", "port":"", "name":""}')
                    self.wfile.close()
                else:
                    myPeerInfo = Utility.GetMyPeerInfo()

                    dictResult = {}
                    dictResult['name'] = myPeerInfo.m_Name
                    dictResult['ip'] = myPeerInfo.m_Ip
                    dictResult['port'] = myPeerInfo.m_Port
                    dictResult['result'] = 'fail'
                    encodedJson = json.dumps(dictResult)

                    self.wfile.write(encodedJson)
                    self.wfile.close()
        else:
            self.send_response(403)
            self.send_header('Content-Type', 'application/json')
            self.end_headers()
 
        return

    def IsMyAddress(self, _peerInfo):
        dictRecvAddress = json.loads(_peerInfo)

        myPeerInfo = Utility.GetMyPeerInfo()

        if dictRecvAddress['name'] == myPeerInfo.m_Name and \
            dictRecvAddress['ip'] == myPeerInfo.m_Ip and \
             dictRecvAddress['port'] == myPeerInfo.m_Port :
            return True
        else:
            return False

 

 
class ThreadedHTTPServer(ThreadingMixIn, HTTPServer):
    allow_reuse_address = True
 
    def shutdown(self):
        self.socket.close()
        HTTPServer.shutdown(self)
 
class HttpServer():
    def __init__(self, ip, port):
        self.server = ThreadedHTTPServer((ip,port), HTTPRequestHandler)
 
    def start(self):
        self.server_thread = threading.Thread(target=self.server.serve_forever)
        self.server_thread.daemon = True
        self.server_thread.start()
 
    def waitForThread(self):
        self.server_thread.join()
 
    def addRecord(self, recordID, jsonEncodedRecord):
        LocalData.records[recordID] = jsonEncodedRecord
 
    def stop(self):
        self.server.shutdown()
        self.waitForThread()
 
if __name__=='__main__':
    parser = argparse.ArgumentParser(description='HTTP Server')
    parser.add_argument('port', type=int, help='Listening port for HTTP Server')
    parser.add_argument('ip', help='HTTP Server IP')
    args = parser.parse_args()
 
    server = HttpServer(args.ip, args.port)
    print 'HTTP Server Running...........'
    server.start()
    server.waitForThread()
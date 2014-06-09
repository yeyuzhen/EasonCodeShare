#!/usr/bin/env python
#coding=utf-8


import httplib, urllib
import json

class HttpClient():
    def __init__(self, _ip, _port):
        self.__httpClient = httplib.HTTPConnection(_ip, _port, timeout=30)

    def SendTelegram(self, _data):
        try:
            body = urllib.urlencode({'data':_data})
            headers = {"Content-type": "application/json",
                       "Accept": "text/plain"}

            self.__httpClient.request("POST", "/api/add_telegram/", body, headers)
            response = self.__httpClient.getresponse()
            return response.status, response.read()
        except Exception, e:
            print 'Exception:', e # TODO 无法发送时的处理
        finally:
            if self.__httpClient:
                self.__httpClient.close()
        return -1, ''

    def CheckAddress(self, _data):
        try:
            body = urllib.urlencode({'data':_data})
            headers = {"Content-type": "application/json",
                       "Accept": "text/plain"}

            self.__httpClient.request("POST", "/api/check_address/", body, headers)
            response = self.__httpClient.getresponse()
            return response.status, response.read()
        except Exception, e: # TODO 无法发送时的处理
            print e
        finally:
            if self.__httpClient:
                self.__httpClient.close()
        return -1, ''

if __name__ == '__main__':
    httpClient = HttpClient('127.0.0.1', 8080)
    responseStatus, responseData = httpClient.CheckAddress('{"ip":"127.0.0.1", "port":"8080", "name":"宁德市公安局"}')
    print responseStatus
    print responseData


# httpClient = None
# try:
#     body = urllib.urlencode({'data':'{"name":"yeyuzhen"}'})
#     headers = {"Content-type": "application/json",
#                "Accept": "text/plain"}

#     httpClient = httplib.HTTPConnection("localhost", 8080, timeout=30)
#     httpClient.request("POST", "/api/check_adress/", body, headers)

#     response = httpClient.getresponse()
#     print response.status
#     print response.reason
#     print response.read()
#     print response.getheaders() #获取头信息
# except Exception, e:
#     print e
# finally:
#     if httpClient:
#         httpClient.close()

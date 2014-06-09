#!/usr/bin/env python
#coding=utf-8

'''
Created on 2013-10-26

@author: yeyuzhen
'''

import sqlite3


# def duplic(fname,lname,msg,ok):
#     dup = False
#     db = dbi()
#     curs = db.cursor()
#     curs.execute("select * from persons where fname = '%s'\
#                 and lname='%s'" % (fname,lname))
#     row = curs.fetchone()
#     if row:
#         ok = False
#         msg += "Duplicate Entry: %s" %(item)
#     return msg, ok


# def duplicedit(fname,lname,id,msg,ok):
#     dup = False
#     db = dbi()
#     curs = db.cursor()
#     curs.execute("select * from persons where fname = '%s'\
#                 and lname='%s' and id != %s" % (fname,lname,id))
#     row = curs.fetchone()
#     if row:
#         ok = False
#         msg += "Duplicate Entry: %s" %(item)
#     return msg, ok

# def getpersonparms(id):
#     db = dbi()
#     cur = db.cursor()
#     cur.execute("select * from persons where id = %s" %(id))
#     k = cur.dictfetchone()
#     return k

# def getpersons():
#     db = dbi()
#     cur = db.cursor()
#     cur.execute("select * from persons order by lname,fname")
#     li = cur.dictfetchall()
#     return li

# def getname(id):
#     res = ''
#     db = dbi()
#     try:
#         cur = db.cursor()
#         cur.execute("select fname from persons\
#                  where id = %s" %(id))
#         res = cur.fetchone()[0]
#     except:
#         pass
#     return res

# def getid(fname,lname):
#     res = ''
#     db = dbi()
#     cur = db.cursor()
#     try:
#         cur.execute("select id from persons\
#                      where fname = '%s' and lname='%s'" %(fname,lname))
#         res = cur.fetchone()[0]
#     except:
#         pass
#     return res

# def deleteperson(id):
#     con = dbi()
#     c = con.cursor()
#     delete = 0
#     try:
#         c.execute("delete from persons\
#         where id = %s" % (int(id)))
#         con.commit() 
#     except:
#         delete = 1
#     return delete

# def updateperson(parms,id):
#     con = dbi()
#     c = con.cursor()
#     c.execute("update persons \
#     set lname='%s', fname='%s', salutation='%s',profession='%s'\
#      where id = %s"
#     % (parms['lname'],parms['fname'],parms['salutation'],
#     parms['profession'],id))
#     con.commit()

# def enterperson(parms):
#     con = dbi()
#     c = con.cursor()
#     c.execute("insert into persons(fname,lname,profession,salutation)\
#        values ('%s', '%s', '%s', '%s')" % (parms['fname'],
#        parms['lname'],parms['profession'],parms['salutation']))
#     con.commit()

class DBConnect():
    def __init__(self):
        self.__dbConnect = sqlite3.connect(r'../db/PTA.db')
        #self.__dbConnect.isolation_level = None  自动提交
        self.__dbConnect.row_factory = self.__dict_factory
        self.__dbCursor = self.__dbConnect.cursor()
    
    def __dict_factory(self, cursor, row):
        d = {}
        for idx, col in enumerate(cursor.description):
            d[col[0]] = row[idx]
        return d
    
    def SelectRootDepartmentInfo(self):
        self.__dbCursor.execute("SELECT * FROM pta_DepartmentInfo WHERE parent_id is NULL")
        return self.__dbCursor.fetchall()

    def SelectAllChildDepartmentInfo(self, _id):
        sqlStatement = "SELECT * FROM pta_DepartmentInfo WHERE parent_id = %d" % _id
        self.__dbCursor.execute(sqlStatement)
        return self.__dbCursor.fetchall()

    def SelectAllDepartmentInfo(self):
        self.__dbCursor.execute("SELECT * FROM pta_DepartmentInfo")
        return self.__dbCursor.fetchall()

    def SelectDepartmentInfo(self):
        self.__dbCursor.execute("SELECT * FROM pta_DepartmentInfo")
        return self.__dbCursor.fetchone()

    def SelectAllTelegramInfo(self):
        self.__dbCursor.execute("SELECT * FROM pta_TelegramInfo")
        return self.__dbCursor.fetchall()

    def SelectMaxTelegramId(self):
        self.__dbCursor.execute("SELECT my_max_telegram_id FROM pta_ConfigInfo")
        return self.__dbCursor.fetchone()

    def SelectMaxDocumentId(self):
        self.__dbCursor.execute("SELECT my_max_document_id FROM pta_ConfigInfo")
        return self.__dbCursor.fetchone()

    def SelectMyPeerInfo(self):
        self.__dbCursor.execute("SELECT my_department_name, my_ip, my_port FROM pta_ConfigInfo")
        return self.__dbCursor.fetchone()

    def SelectMyDepartmentName(self):
        self.__dbCursor.execute("SELECT my_department_name FROM pta_ConfigInfo")
        return self.__dbCursor.fetchone()

    def InsertOutTelegramInfo(self, _telegramInfo):
        self.__dbCursor.execute("INSERT INTO pta_Out_TelegramInfo(telegram_id, \
                                                                  document_id, \
                                                                  date_time, \
                                                                  department_name, \
                                                                  title, \
                                                                  urgency_level, \
                                                                  secret_level, \
                                                                  page_number, \
                                                                  operator, \
                                                                  send_to_list, \
                                                                  copy_to_list, \
                                                                  copy_report_list) \
            VALUES ('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s')" % \
                                                                 (_telegramInfo['telegram_id'],
                                                                  _telegramInfo['document_id'],
                                                                  _telegramInfo['date_time'],
                                                                  _telegramInfo['department_name'],
                                                                  _telegramInfo['title'],
                                                                  _telegramInfo['urgency_level'],
                                                                  _telegramInfo['secret_level'],
                                                                  _telegramInfo['page_number'],
                                                                  _telegramInfo['operator'],
                                                                  _telegramInfo['send_to_list'],
                                                                  _telegramInfo['copy_to_list'],
                                                                  _telegramInfo['copy_report_list']))
        self.__dbConnect.commit()

    def InsertInTelegramInfo(self, _telegramInfo):
        self.__dbCursor.execute("INSERT INTO pta_In_TelegramInfo(telegram_id, \
                                                                document_id, \
                                                                date_time, \
                                                                department_name, \
                                                                title, \
                                                                urgency_level, \
                                                                secret_level, \
                                                                page_number, \
                                                                operator, \
                                                                send_to_list, \
                                                                copy_to_list, \
                                                                copy_report_list) \
          VALUES ('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s')" % \
                                                               (_telegramInfo['telegram_id'],
                                                                _telegramInfo['document_id'],
                                                                _telegramInfo['date_time'],
                                                                _telegramInfo['department_name'],
                                                                _telegramInfo['title'],
                                                                _telegramInfo['urgency_level'],
                                                                _telegramInfo['secret_level'],
                                                                _telegramInfo['page_number'],
                                                                _telegramInfo['operator'],
                                                                _telegramInfo['send_to_list'],
                                                                _telegramInfo['copy_to_list'],
                                                                _telegramInfo['copy_report_list']))
        self.__dbConnect.commit()

class Department():
    def __init__(self, _info):
        self.m_Id = _info["id"]
        self.m_DepartmentId = _info["department_id"]
        self.m_Name = _info["name"]
        self.m_ParentId = _info["parent_id"]
        self.m_Ip = _info["ip"]
        self.m_Port = _info["port"]

class Peer():
    def __init__(self, _info):
        self.m_Name = _info['my_department_name']
        self.m_Ip = _info['my_ip']
        self.m_Port = _info['my_port']


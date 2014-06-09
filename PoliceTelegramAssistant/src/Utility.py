#!/usr/bin/env python
#coding=utf-8

'''
Created on 2013-10-27

@author: yeyuzhen
'''
import wx
from Model import *
from HttpClient import HttpClient 

class Utility():
	@classmethod
	def GetRootDepartment(cls):
		DB = DBConnect()
		listRootDepartmentInfo = DB.SelectRootDepartmentInfo()
		rootDepartment = Department(listRootDepartmentInfo[0])
		return rootDepartment
	
	@classmethod
	def GetAllChildDepartment(cls, _id):
		DB = DBConnect()
		listAllChildDepartmentInfo = DB.SelectAllChildDepartmentInfo(_id)
		
		listAllChildDepartment = []
		for index in range(len(listAllChildDepartmentInfo)) :
			department = Department(listAllChildDepartmentInfo[index])
			listAllChildDepartment.append(department)
	
		return listAllChildDepartment
	
	@classmethod
	def FillAllChildDepartmentItem(cls, _currentDepartmentItemId, _treeCtrl_):
		currentDepartmentItemData = _treeCtrl_.GetItemData(_currentDepartmentItemId)
		currentDepartment = currentDepartmentItemData.GetData()
	
		listAllChildDepartment = Utility.GetAllChildDepartment(currentDepartment.m_Id)
	
		for department in listAllChildDepartment:
			departmentItemId = _treeCtrl_.AppendItem(_currentDepartmentItemId, 
				department.m_Name, data=wx.TreeItemData(department))
			Utility.FillAllChildDepartmentItem(departmentItemId, _treeCtrl_)
	
	@classmethod
	def GetMyDepartmentName(cls):
		DB = DBConnect()
		dictMyDepartmentName = DB.SelectMyDepartmentName()
		return dictMyDepartmentName['my_department_name']
	
	@classmethod
	def GetMaxTelegramId(cls):
		DB = DBConnect()
		dictMaxTelegramId = DB.SelectMaxTelegramId()
		return dictMaxTelegramId['my_max_telegram_id']
	
	@classmethod
	def GetMaxDocumentId(cls):
		DB = DBConnect()
		dictMaxDocumentId = DB.SelectMaxDocumentId()
		return dictMaxDocumentId['my_max_document_id']
	
	@classmethod
	def GetMyPeerInfo(cls):
		DB = DBConnect()
		dictMyPeerInfo = DB.SelectMyPeerInfo()
		myPeerInfo = Peer(dictMyPeerInfo)
		return myPeerInfo
	
	@classmethod
	def SaveOutTelegramInfo(cls, _telegramInfo):
		DB = DBConnect()
		DB.InsertOutTelegramInfo(_telegramInfo)
	
	@classmethod
	def SaveInTelegramInfo(cls, _dictTelegramInfo):
		DB = DBConnect() # 重复判断，重复的就不要再入库了。
		DB.InsertInTelegramInfo(_dictTelegramInfo)
	
	@classmethod
	def SendTelegramToDepartmentList(cls, _listDepartment, _stringData):
		for item in _listDepartment:
			httpClient = HttpClient(item.m_Ip, int(item.m_Port))  # FIXME 部分失败如何处理？？？
			httpClient.SendTelegram(_stringData)
	
	@classmethod
	def SendTelegramToDepartment(cls, _department, _stringData):
		print 'Ip:',_department.m_Ip
		print 'Port:',_department.m_Port
		httpClient = HttpClient(_department.m_Ip, int(_department.m_Port))
		httpClient.SendTelegram(_stringData)






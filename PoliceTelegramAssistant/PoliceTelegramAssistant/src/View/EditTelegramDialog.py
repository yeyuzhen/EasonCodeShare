#!/usr/bin/env python
#coding=utf-8

import wx
import json

from ViewBase import EditTelegramDialogBase
from Utility import Utility
from DisplayAllDepartmentsDialog import DisplayAllDepartmentsDialog
from SendingDialog import SendingDialog



class EditTelegramDialog(EditTelegramDialogBase):
    def __init__(self, parent):
        EditTelegramDialogBase.__init__(self, parent)
        self.ListDepartmentSendTo = []
        self.ListDepartmentCopyTo = []
        self.ListDepartmentCopyReport = []

        #自动生成电报编号
        stringMaxTelegramId = Utility.GetMaxTelegramId()
        self.textCtrl_Telegram_Id.Clear()
        self.textCtrl_Telegram_Id.AppendText(stringMaxTelegramId)
        self.textCtrl_Telegram_Id.SetEditable(False)

        #自动生成电报文号
        stringMaxDocumentId = Utility.GetMaxDocumentId()
        self.textCtrl_Document_Id.Clear()
        self.textCtrl_Document_Id.AppendText(stringMaxDocumentId)
        self.textCtrl_Document_Id.SetEditable(False)

        #填充发电部门
        stringMyDepartmentName = Utility.GetMyDepartmentName()
        self.comboBox_DepartmentName.SetValue(stringMyDepartmentName)

    

    def OnSendTo( self, event ):
        AllDepartments = DisplayAllDepartmentsDialog(self, self.ListDepartmentSendTo)
        
        # 需要把对应的 Department 作为 TreeItemData 附加到节点

        rootDepartment = Utility.GetRootDepartment()
        rootItemId = AllDepartments.treeCtrl_AllDepartments.AddRoot(rootDepartment.m_Name, 
            data=wx.TreeItemData(rootDepartment))
        # rootItemData = AllDepartments.treeCtrl_AllDepartments.GetItemData(rootItemId)
        # rootData = rootItemData.GetData()
        # print rootData.m_Id, rootData.m_DepartmentId, rootData.m_Name, rootData.m_ParentId

        # 用递归方式填充
        Utility.FillAllChildDepartmentItem(rootItemId, AllDepartments.treeCtrl_AllDepartments)
        
        AllDepartments.treeCtrl_AllDepartments.ExpandAll()
        AllDepartments.ShowModal()

        self.FillSendToListBoxFromListDepartmentSendTo()
    


    def OnCopyTo( self, event ):
        AllDepartments = DisplayAllDepartmentsDialog(self, self.ListDepartmentCopyTo)
        
        rootDepartment = Utility.GetRootDepartment()
        rootItemId = AllDepartments.treeCtrl_AllDepartments.AddRoot(rootDepartment.m_Name,
            data=wx.TreeItemData(rootDepartment))

        Utility.FillAllChildDepartmentItem(rootItemId, AllDepartments.treeCtrl_AllDepartments)
        
        AllDepartments.treeCtrl_AllDepartments.ExpandAll()
        AllDepartments.ShowModal()

        self.FillCopyToListBoxFromListDepartmentCopyTo()



    def OnButtonCopyReportClick( self, event ):
        AllDepartments = DisplayAllDepartmentsDialog(self, self.ListDepartmentCopyReport)

        rootDepartment = Utility.GetRootDepartment()
        rootItemId = AllDepartments.treeCtrl_AllDepartments.AddRoot(rootDepartment.m_Name,
            data=wx.TreeItemData(rootDepartment))

        Utility.FillAllChildDepartmentItem(rootItemId, AllDepartments.treeCtrl_AllDepartments)

        AllDepartments.treeCtrl_AllDepartments.ExpandAll()
        AllDepartments.ShowModal()

        self.FillCopyReportListBoxFromListDepartmentCopyReport()



    def OnDialogCloseClick( self, event ):
        self.EndModal(0)

    def OnButtonSaveSendClick( self, event ):
        dictTeleInfo = {}
        dictTeleInfo['telegram_id'] = self.textCtrl_Telegram_Id.GetLineText(0)
        dictTeleInfo['document_id'] = self.textCtrl_Document_Id.GetLineText(0)
        dictTeleInfo['date_time'] = self.textCtrl_DateTime.GetLineText(0)
        dictTeleInfo['department_name'] = self.comboBox_DepartmentName.GetValue()
        dictTeleInfo['title'] = self.textCtrl_Title.GetLineText(0)
        dictTeleInfo['urgency_level'] = self.comboBox_UrgencyLevel.GetValue()
        dictTeleInfo['secret_level'] = self.comboBox_SecretLevel.GetValue()
        dictTeleInfo['page_number'] = self.textCtrl_PageNumber.GetLineText(0)
        dictTeleInfo['operator'] = self.comboBox_Operator.GetValue()
        dictTeleInfo['send_to_list'] = ''  # 防止字段缺失
        dictTeleInfo['copy_to_list'] = ''  # 防止字段缺失
        dictTeleInfo['copy_report_list'] = ''  # 防止字段缺失

        index = 0
        for item in self.ListDepartmentSendTo:
            if index == 0:
                dictTeleInfo['send_to_list'] = item.m_Name
            else:
                dictTeleInfo['send_to_list'] += '|'
                dictTeleInfo['send_to_list'] += item.m_Name
            index += 1
        
        index = 0
        for item in self.ListDepartmentCopyTo:
            if index == 0:
                dictTeleInfo['copy_to_list'] = item.m_Name
            else:
                dictTeleInfo['copy_to_list'] += '|'
                dictTeleInfo['copy_to_list'] += item.m_Name
            index += 1

        index = 0
        for item in self.ListDepartmentCopyReport:
            if index == 0:
                dictTeleInfo['copy_report_list'] = item.m_Name
            else:
                dictTeleInfo['copy_report_list'] += '|'
                dictTeleInfo['copy_report_list'] += item.m_Name
            index += 1

        # 转成 Json 串
        encodedJson = json.dumps(dictTeleInfo)

        # 发送 Json 串到 send_to_list、copy_to_list 和 copy_report_list 对应的部门
        # 要弹出一个发送过程界面
        # httpClient = HttpClient('127.0.0.1', 8080)
        # responseStatus, responseData = httpClient.SendTelegram(encodedJson)
        # print 'responseStatus:',responseStatus
        # print 'responseData:',responseData

        sendingDialog = SendingDialog(self, encodedJson, self.ListDepartmentSendTo, 
            self.ListDepartmentCopyTo, self.ListDepartmentCopyReport)
        sendingDialogReturnCode = sendingDialog.ShowModal()

        # 完全发送成功之后才能把这个电报保存下来
        Utility.SaveOutTelegramInfo(dictTeleInfo)



    def OnButtonResetClick( self, event ):
        # 清空发电编号
        self.textCtrl_Telegram_Id.Clear()
        stringMaxTelegramId = Utility.GetMaxTelegramId()
        self.textCtrl_Telegram_Id.AppendText(stringMaxTelegramId)

        #清空发电文号   ！！！要重新载入自动生成的编号
        self.textCtrl_Document_Id.Clear()
        stringMaxDocumentId = Utility.GetMaxDocumentId()
        self.textCtrl_Document_Id.AppendText(stringMaxDocumentId)

        #清空发电时间
        self.textCtrl_DateTime.Clear()

        #清空列表
        self.ListDepartmentSendTo = []
        self.ListDepartmentCopyTo = []
        self.ListDepartmentCopyReport = []

        self.FillSendToListBoxFromListDepartmentSendTo()
        self.FillCopyToListBoxFromListDepartmentCopyTo()
        self.FillCopyReportListBoxFromListDepartmentCopyReport()


    
    def OnButtonCancelClick( self, event ):
        self.EndModal(0)



    def FillSendToListBoxFromListDepartmentSendTo(self):
        listSendTo = []
        for item in self.ListDepartmentSendTo:
            listSendTo.append(item.m_Name)

        self.listBox_SendTo.Set(listSendTo)



    def FillCopyToListBoxFromListDepartmentCopyTo(self):
        listCopyTo = []
        for item in self.ListDepartmentCopyTo:
            listCopyTo.append(item.m_Name)

        self.listBox_CopyTo.Set(listCopyTo)

    def FillCopyReportListBoxFromListDepartmentCopyReport(self):
        listCopyReport = []
        for item in self.ListDepartmentCopyReport:
            listCopyReport.append(item.m_Name)

        self.listBox_CopyReport.Set(listCopyReport)

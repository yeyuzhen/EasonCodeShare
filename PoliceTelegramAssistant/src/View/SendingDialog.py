#!/usr/bin/env python
#coding=utf-8

from ViewBase import SendingDialogBase
from Utility import Utility

class SendingDialog(SendingDialogBase):
    def __init__(self, parent, telegramInfoJson, listDepartmentSendTo, 
            listDepartmentCopyTo, listDepartmentCopyReport):
        SendingDialogBase.__init__(self, parent)
        self.TelegramInfoJson = telegramInfoJson
        self.ListDepartmentSendTo = listDepartmentSendTo
        self.ListDepartmentCopyTo = listDepartmentCopyTo
        self.ListDepartmentCopyReport = listDepartmentCopyReport

        # TODO 计算需要发送的节点总数(用于计算百分比)
        self.DestinationDepartmentCount = len(self.ListDepartmentSendTo) \
                                        + len(self.ListDepartmentCopyTo) \
                                        + len(self.ListDepartmentCopyReport)
        self.CurrentDestinationDepartment = 0

        # 逐个发送给主送
        for item in self.ListDepartmentSendTo:
            # TODO 发送前日志
            self.textCtrl_SendingLog.AppendText(u'主送[%s],正在发送...\n' % item.m_Name)
            Utility.SendTelegramToDepartment(item, self.TelegramInfoJson)  # TODO成功或失败？？
            # TODO 发送后日志
            self.textCtrl_SendingLog.AppendText(u'主送[%s],发送成功...\n' % item.m_Name)
            # TODO 设置进度条
            self.CurrentDestinationDepartment += 1
            self.gauge_SendingStatus.SetValue(self.CurrentDestinationDepartment * 100 / self.DestinationDepartmentCount) 

        # TODO 逐个发送给抄送


        # TODO 逐个发送给抄报

    def OnCancelClick( self, event ):
        self.EndModal(0)  # 点击取消，业务要如何回滚？？？

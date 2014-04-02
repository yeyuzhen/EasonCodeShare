#!/usr/bin/env python
#coding=utf-8

from ViewBase import MainFrameBase
from EditTelegramDialog import EditTelegramDialog


class MainFrame(MainFrameBase):
    def __init__(self, parent):
        MainFrameBase.__init__(self, None)

        self.__InsertInboxListColumnTitle()
        self.__InsertOutboxListColumnTitle()


    def OnEditNew( self, event ):
        EditNewTelegramDialog = EditTelegramDialog(self)
        EditNewTelegramDialog.ShowModal()

    def __InsertInboxListColumnTitle(self):
        self.listCtrl_Inbox.InsertColumn(0, u"发电编号")
        self.listCtrl_Inbox.InsertColumn(1, u"发电文号")
        self.listCtrl_Inbox.InsertColumn(2, u"发电时间")
        self.listCtrl_Inbox.InsertColumn(3, u"发电单位")
        self.listCtrl_Inbox.InsertColumn(4, u"文件标题")
        self.listCtrl_Inbox.InsertColumn(5, u"等级")
        self.listCtrl_Inbox.InsertColumn(6, u"密级")
        self.listCtrl_Inbox.InsertColumn(7, u"页数")
        self.listCtrl_Inbox.InsertColumn(8, u"值机员")
    
    def __InsertOutboxListColumnTitle(self):
        self.listCtrl_Outbox.InsertColumn(0, u"发电编号")
        self.listCtrl_Outbox.InsertColumn(1, u"发电文号")
        self.listCtrl_Outbox.InsertColumn(2, u"发电时间")
        self.listCtrl_Outbox.InsertColumn(3, u"发电单位")
        self.listCtrl_Outbox.InsertColumn(4, u"文件标题")
        self.listCtrl_Outbox.InsertColumn(5, u"等级")
        self.listCtrl_Outbox.InsertColumn(6, u"密级")
        self.listCtrl_Outbox.InsertColumn(7, u"页数")
        self.listCtrl_Outbox.InsertColumn(8, u"值机员")

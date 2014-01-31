#!/usr/bin/env python
#coding=utf-8
'''
Created on 2013-7-10

@author: yeyuzhen
'''
import wx
from ViewBase import MainFrameBase, OnlyCloseButtonDialogBase

class OnlyCloseButtonDialog(OnlyCloseButtonDialogBase):
    def __init__(self, parent):
        OnlyCloseButtonDialogBase.__init__(self, None)
    
    def OnClose(self, event):
        self.EndModal(0)

class MainFrame(MainFrameBase):
    def __init__(self, parent):
        MainFrameBase.__init__(self, None)
    
    def OnClickMe(self, event):
        dialog = OnlyCloseButtonDialog(None)
        dialog.ShowModal()

class Application(wx.App):
    def OnInit(self):
        self.frame = MainFrame(parent=None)
        self.frame.Show()
        self.SetTopWindow(self.frame)
        return True

if __name__ == '__main__':
    app = Application(redirect=False)
    app.MainLoop()
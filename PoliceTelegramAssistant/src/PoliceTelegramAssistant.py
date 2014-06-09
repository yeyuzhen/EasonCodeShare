#!/usr/bin/env python
#coding=utf-8

import sys
sys.path.append("..")  # TODO 如何更优雅的导入顶层包到 sys.path ???

import wx
from View.MainFrame import MainFrame
from View.LoginDialog import LoginDialog
from HttpServer import HttpServer

class Application(wx.App):

    def OnInit(self):
        self.MainFrame = MainFrame(None)
        self.LoginDialog = LoginDialog(self.MainFrame)
        LoginResult = self.LoginDialog.ShowModal()
        if LoginResult == 1 :
            self.MainFrame.Show()
            self.SetTopWindow(self.MainFrame)
            return True
        else :
            return False

if __name__ == '__main__':
    server = HttpServer('0.0.0.0', 8080)
    print 'HTTP Server Running...........'
    server.start()
    app = Application(redirect=False)
    app.MainLoop()
    server.stop()


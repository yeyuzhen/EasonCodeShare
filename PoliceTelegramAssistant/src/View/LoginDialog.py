#!/usr/bin/env python
#coding=utf-8

from ViewBase import LoginDialogBase

class LoginDialog(LoginDialogBase):
    def __init__(self, parent):
        LoginDialogBase.__init__(self, parent)
    
    def OnButtonClickLogin( self, event ):
        self.EndModal(1)
    
    def OnButtonClickQuit( self, event ):
        self.EndModal(0)
# -*- coding: utf-8 -*- 

###########################################################################
## Python code generated with wxFormBuilder (version Oct  8 2012)
## http://www.wxformbuilder.org/
##
## PLEASE DO "NOT" EDIT THIS FILE!
###########################################################################

import wx
import wx.xrc

###########################################################################
## Class MainFrameBase
###########################################################################

class MainFrameBase ( wx.Frame ):
	
	def __init__( self, parent ):
		wx.Frame.__init__ ( self, parent, id = wx.ID_ANY, title = u"wxFBDemo", pos = wx.DefaultPosition, size = wx.Size( 500,300 ), style = wx.DEFAULT_FRAME_STYLE|wx.TAB_TRAVERSAL )
		
		self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
		
		bSizer1 = wx.BoxSizer( wx.VERTICAL )
		
		
		bSizer1.AddSpacer( ( 0, 0), 1, wx.EXPAND, 5 )
		
		bSizer2 = wx.BoxSizer( wx.HORIZONTAL )
		
		
		bSizer2.AddSpacer( ( 0, 0), 1, wx.EXPAND, 5 )
		
		self.btn_ClickMe = wx.Button( self, wx.ID_ANY, u"点我", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer2.Add( self.btn_ClickMe, 1, wx.ALL|wx.EXPAND, 5 )
		
		
		bSizer2.AddSpacer( ( 0, 0), 1, wx.EXPAND, 5 )
		
		
		bSizer1.Add( bSizer2, 1, wx.EXPAND, 5 )
		
		
		bSizer1.AddSpacer( ( 0, 0), 1, wx.EXPAND, 5 )
		
		
		self.SetSizer( bSizer1 )
		self.Layout()
		
		self.Centre( wx.BOTH )
		
		# Connect Events
		self.btn_ClickMe.Bind( wx.EVT_BUTTON, self.OnClickMe )
	
	def __del__( self ):
		pass
	
	
	# Virtual event handlers, overide them in your derived class
	def OnClickMe( self, event ):
		event.Skip()
	

###########################################################################
## Class OnlyCloseButtonDialogBase
###########################################################################

class OnlyCloseButtonDialogBase ( wx.Dialog ):
	
	def __init__( self, parent ):
		wx.Dialog.__init__ ( self, parent, id = wx.ID_ANY, title = u"DialogDemo", pos = wx.DefaultPosition, size = wx.Size( 254,139 ), style = wx.DEFAULT_DIALOG_STYLE )
		
		self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
		
		bSizer4 = wx.BoxSizer( wx.VERTICAL )
		
		
		bSizer4.AddSpacer( ( 0, 0), 1, wx.EXPAND, 5 )
		
		bSizer6 = wx.BoxSizer( wx.HORIZONTAL )
		
		
		bSizer6.AddSpacer( ( 0, 0), 1, wx.EXPAND, 5 )
		
		self.btn_Close = wx.Button( self, wx.ID_ANY, u"关闭", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer6.Add( self.btn_Close, 1, wx.ALL|wx.EXPAND, 5 )
		
		
		bSizer4.Add( bSizer6, 1, wx.EXPAND, 5 )
		
		
		self.SetSizer( bSizer4 )
		self.Layout()
		
		self.Centre( wx.BOTH )
		
		# Connect Events
		self.btn_Close.Bind( wx.EVT_BUTTON, self.OnClose )
	
	def __del__( self ):
		pass
	
	
	# Virtual event handlers, overide them in your derived class
	def OnClose( self, event ):
		event.Skip()
	


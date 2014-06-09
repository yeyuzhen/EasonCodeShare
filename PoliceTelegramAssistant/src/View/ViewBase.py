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
## Class EditTelegramDialogBase
###########################################################################

class EditTelegramDialogBase ( wx.Dialog ):
	
	def __init__( self, parent ):
		wx.Dialog.__init__ ( self, parent, id = wx.ID_ANY, title = u"写电报", pos = wx.DefaultPosition, size = wx.Size( 679,473 ), style = wx.DEFAULT_DIALOG_STYLE )
		
		self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
		
		boxSizer_VTopSizer = wx.BoxSizer( wx.VERTICAL )
		
		boxSizer_HColumn1Sizer = wx.BoxSizer( wx.HORIZONTAL )
		
		boxSizer_HTeleSerial = wx.BoxSizer( wx.HORIZONTAL )
		
		self.label_TeleSerial = wx.StaticText( self, wx.ID_ANY, u"发电编号：", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.label_TeleSerial.Wrap( -1 )
		boxSizer_HTeleSerial.Add( self.label_TeleSerial, 0, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		self.textCtrl_Telegram_Id = wx.TextCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		boxSizer_HTeleSerial.Add( self.textCtrl_Telegram_Id, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		
		boxSizer_HColumn1Sizer.Add( boxSizer_HTeleSerial, 1, wx.EXPAND|wx.TOP|wx.RIGHT|wx.LEFT, 5 )
		
		
		boxSizer_HColumn1Sizer.AddSpacer( ( 0, 0), 0, wx.EXPAND|wx.RIGHT|wx.LEFT, 5 )
		
		boxSizer_HTeleSerial1 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.label_TeleTextSerial = wx.StaticText( self, wx.ID_ANY, u"发电文号：", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.label_TeleTextSerial.Wrap( -1 )
		boxSizer_HTeleSerial1.Add( self.label_TeleTextSerial, 0, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		self.textCtrl_Document_Id = wx.TextCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		boxSizer_HTeleSerial1.Add( self.textCtrl_Document_Id, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		
		boxSizer_HColumn1Sizer.Add( boxSizer_HTeleSerial1, 1, wx.EXPAND|wx.TOP|wx.RIGHT|wx.LEFT, 5 )
		
		
		boxSizer_VTopSizer.Add( boxSizer_HColumn1Sizer, 0, wx.ALL|wx.EXPAND, 5 )
		
		boxSizer_HColumn2Sizer = wx.BoxSizer( wx.HORIZONTAL )
		
		boxSizer_HTeleDateTime = wx.BoxSizer( wx.HORIZONTAL )
		
		self.staticText_TeleDateTime = wx.StaticText( self, wx.ID_ANY, u"发电时间：", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.staticText_TeleDateTime.Wrap( -1 )
		boxSizer_HTeleDateTime.Add( self.staticText_TeleDateTime, 0, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		self.textCtrl_DateTime = wx.TextCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		boxSizer_HTeleDateTime.Add( self.textCtrl_DateTime, 1, wx.ALIGN_CENTER_VERTICAL|wx.ALL, 5 )
		
		self.button_DateTimeSelect = wx.Button( self, wx.ID_ANY, u"...", wx.DefaultPosition, wx.Size( 30,-1 ), 0 )
		boxSizer_HTeleDateTime.Add( self.button_DateTimeSelect, 0, wx.ALIGN_CENTER_VERTICAL|wx.TOP|wx.BOTTOM|wx.RIGHT, 5 )
		
		
		boxSizer_HColumn2Sizer.Add( boxSizer_HTeleDateTime, 1, wx.EXPAND|wx.RIGHT|wx.LEFT|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		
		boxSizer_HColumn2Sizer.AddSpacer( ( 0, 0), 0, wx.RIGHT|wx.LEFT|wx.EXPAND, 5 )
		
		boxSizer_HTeleDepartment = wx.BoxSizer( wx.HORIZONTAL )
		
		self.staticText_TeleDepartment = wx.StaticText( self, wx.ID_ANY, u"发电单位：", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.staticText_TeleDepartment.Wrap( -1 )
		boxSizer_HTeleDepartment.Add( self.staticText_TeleDepartment, 0, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		comboBox_DepartmentNameChoices = []
		self.comboBox_DepartmentName = wx.ComboBox( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, comboBox_DepartmentNameChoices, 0 )
		boxSizer_HTeleDepartment.Add( self.comboBox_DepartmentName, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		
		boxSizer_HColumn2Sizer.Add( boxSizer_HTeleDepartment, 1, wx.EXPAND|wx.RIGHT|wx.LEFT|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		
		boxSizer_VTopSizer.Add( boxSizer_HColumn2Sizer, 0, wx.EXPAND|wx.ALL, 5 )
		
		boxSizer_HColumn3Sizer = wx.BoxSizer( wx.HORIZONTAL )
		
		boxSizer_HTeleFileTitle = wx.BoxSizer( wx.HORIZONTAL )
		
		self.staticText_TeleFileTitle = wx.StaticText( self, wx.ID_ANY, u"文件标题：", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.staticText_TeleFileTitle.Wrap( -1 )
		boxSizer_HTeleFileTitle.Add( self.staticText_TeleFileTitle, 0, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		self.textCtrl_Title = wx.TextCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		boxSizer_HTeleFileTitle.Add( self.textCtrl_Title, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		
		boxSizer_HColumn3Sizer.Add( boxSizer_HTeleFileTitle, 1, wx.EXPAND|wx.ALIGN_CENTER_VERTICAL|wx.RIGHT|wx.LEFT, 5 )
		
		
		boxSizer_VTopSizer.Add( boxSizer_HColumn3Sizer, 0, wx.EXPAND|wx.ALL, 5 )
		
		boxSizer_HColumn4Sizer = wx.BoxSizer( wx.HORIZONTAL )
		
		boxSizer_HLevel = wx.BoxSizer( wx.HORIZONTAL )
		
		self.staticText_Level = wx.StaticText( self, wx.ID_ANY, u"等级：", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.staticText_Level.Wrap( -1 )
		boxSizer_HLevel.Add( self.staticText_Level, 0, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		comboBox_UrgencyLevelChoices = [ u"特提", u"特级", u"加急", u"平急" ]
		self.comboBox_UrgencyLevel = wx.ComboBox( self, wx.ID_ANY, u"平急", wx.DefaultPosition, wx.DefaultSize, comboBox_UrgencyLevelChoices, 0 )
		boxSizer_HLevel.Add( self.comboBox_UrgencyLevel, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		
		boxSizer_HColumn4Sizer.Add( boxSizer_HLevel, 1, wx.EXPAND|wx.RIGHT|wx.LEFT|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		boxSizer_CryptoLevel = wx.BoxSizer( wx.HORIZONTAL )
		
		self.staticText_CryptoLevel = wx.StaticText( self, wx.ID_ANY, u"密级：", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.staticText_CryptoLevel.Wrap( -1 )
		boxSizer_CryptoLevel.Add( self.staticText_CryptoLevel, 0, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		comboBox_SecretLevelChoices = [ u"绝密", u"机密", u"秘密" ]
		self.comboBox_SecretLevel = wx.ComboBox( self, wx.ID_ANY, u"秘密", wx.DefaultPosition, wx.DefaultSize, comboBox_SecretLevelChoices, 0 )
		boxSizer_CryptoLevel.Add( self.comboBox_SecretLevel, 1, wx.ALL, 5 )
		
		
		boxSizer_HColumn4Sizer.Add( boxSizer_CryptoLevel, 1, wx.EXPAND|wx.RIGHT|wx.LEFT|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		boxSizer_HPagesNumber = wx.BoxSizer( wx.HORIZONTAL )
		
		self.staticText_PagesNumber = wx.StaticText( self, wx.ID_ANY, u"页数：", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.staticText_PagesNumber.Wrap( -1 )
		boxSizer_HPagesNumber.Add( self.staticText_PagesNumber, 0, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		self.textCtrl_PageNumber = wx.TextCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		boxSizer_HPagesNumber.Add( self.textCtrl_PageNumber, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		
		boxSizer_HColumn4Sizer.Add( boxSizer_HPagesNumber, 1, wx.EXPAND|wx.RIGHT|wx.LEFT|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		boxSizer_HOperator = wx.BoxSizer( wx.HORIZONTAL )
		
		self.staticText_Operator = wx.StaticText( self, wx.ID_ANY, u"值机员：", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.staticText_Operator.Wrap( -1 )
		boxSizer_HOperator.Add( self.staticText_Operator, 0, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		comboBox_OperatorChoices = []
		self.comboBox_Operator = wx.ComboBox( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, comboBox_OperatorChoices, 0 )
		boxSizer_HOperator.Add( self.comboBox_Operator, 1, wx.ALL|wx.ALIGN_CENTER_VERTICAL, 5 )
		
		
		boxSizer_HColumn4Sizer.Add( boxSizer_HOperator, 1, wx.EXPAND|wx.ALIGN_CENTER_VERTICAL|wx.RIGHT|wx.LEFT, 5 )
		
		
		boxSizer_VTopSizer.Add( boxSizer_HColumn4Sizer, 0, wx.EXPAND|wx.ALL, 5 )
		
		boxSizer_HColumn5Sizer = wx.BoxSizer( wx.HORIZONTAL )
		
		boxSizer_VSendTo = wx.BoxSizer( wx.VERTICAL )
		
		self.button_SendTo = wx.Button( self, wx.ID_ANY, u"主送...", wx.DefaultPosition, wx.DefaultSize, wx.BU_LEFT )
		boxSizer_VSendTo.Add( self.button_SendTo, 0, wx.ALL, 5 )
		
		listBox_SendToChoices = []
		self.listBox_SendTo = wx.ListBox( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, listBox_SendToChoices, 0 )
		boxSizer_VSendTo.Add( self.listBox_SendTo, 1, wx.ALL|wx.EXPAND, 5 )
		
		
		boxSizer_HColumn5Sizer.Add( boxSizer_VSendTo, 1, wx.EXPAND|wx.RIGHT|wx.LEFT|wx.ALIGN_BOTTOM, 5 )
		
		boxSizer_VCopyTo = wx.BoxSizer( wx.VERTICAL )
		
		self.button_CopyTo = wx.Button( self, wx.ID_ANY, u"抄送...", wx.DefaultPosition, wx.DefaultSize, wx.BU_LEFT )
		boxSizer_VCopyTo.Add( self.button_CopyTo, 0, wx.TOP|wx.BOTTOM|wx.RIGHT, 5 )
		
		listBox_CopyToChoices = []
		self.listBox_CopyTo = wx.ListBox( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, listBox_CopyToChoices, 0 )
		boxSizer_VCopyTo.Add( self.listBox_CopyTo, 1, wx.EXPAND|wx.TOP|wx.BOTTOM|wx.RIGHT, 5 )
		
		
		boxSizer_HColumn5Sizer.Add( boxSizer_VCopyTo, 1, wx.EXPAND|wx.RIGHT|wx.LEFT|wx.ALIGN_BOTTOM, 5 )
		
		
		boxSizer_VTopSizer.Add( boxSizer_HColumn5Sizer, 1, wx.EXPAND, 5 )
		
		bSizer_HColumn6Sizer = wx.BoxSizer( wx.HORIZONTAL )
		
		boxSizer_VSendTo1 = wx.BoxSizer( wx.VERTICAL )
		
		self.button_CopyReport = wx.Button( self, wx.ID_ANY, u"抄报...", wx.DefaultPosition, wx.DefaultSize, wx.BU_LEFT )
		boxSizer_VSendTo1.Add( self.button_CopyReport, 0, wx.ALL, 5 )
		
		listBox_CopyReportChoices = []
		self.listBox_CopyReport = wx.ListBox( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, listBox_CopyReportChoices, 0 )
		boxSizer_VSendTo1.Add( self.listBox_CopyReport, 1, wx.ALL|wx.EXPAND, 5 )
		
		
		bSizer_HColumn6Sizer.Add( boxSizer_VSendTo1, 1, wx.EXPAND, 5 )
		
		boxSizer_VCommandArea = wx.BoxSizer( wx.HORIZONTAL )
		
		self.button_SaveSend = wx.Button( self, wx.ID_ANY, u"保存并发送", wx.DefaultPosition, wx.DefaultSize, 0 )
		boxSizer_VCommandArea.Add( self.button_SaveSend, 1, wx.EXPAND|wx.ALL, 5 )
		
		bSizer34 = wx.BoxSizer( wx.VERTICAL )
		
		
		bSizer34.AddSpacer( ( 0, 0), 1, 0, 5 )
		
		bSizer35 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.button_Reset = wx.Button( self, wx.ID_ANY, u"重填", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer35.Add( self.button_Reset, 1, wx.ALL|wx.EXPAND, 5 )
		
		self.button_Cancel = wx.Button( self, wx.ID_ANY, u"取消", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer35.Add( self.button_Cancel, 1, wx.ALL|wx.EXPAND, 5 )
		
		
		bSizer34.Add( bSizer35, 1, 0, 5 )
		
		
		boxSizer_VCommandArea.Add( bSizer34, 1, wx.EXPAND, 5 )
		
		
		bSizer_HColumn6Sizer.Add( boxSizer_VCommandArea, 0, wx.EXPAND|wx.RIGHT|wx.LEFT|wx.ALIGN_BOTTOM, 5 )
		
		
		boxSizer_VTopSizer.Add( bSizer_HColumn6Sizer, 1, wx.EXPAND|wx.RIGHT|wx.LEFT, 5 )
		
		
		self.SetSizer( boxSizer_VTopSizer )
		self.Layout()
		
		self.Centre( wx.BOTH )
		
		# Connect Events
		self.Bind( wx.EVT_CLOSE, self.OnDialogCloseClick )
		self.button_DateTimeSelect.Bind( wx.EVT_BUTTON, self.OnDataTimeSelect )
		self.button_SendTo.Bind( wx.EVT_BUTTON, self.OnSendTo )
		self.button_CopyTo.Bind( wx.EVT_BUTTON, self.OnCopyTo )
		self.button_CopyReport.Bind( wx.EVT_BUTTON, self.OnButtonCopyReportClick )
		self.button_SaveSend.Bind( wx.EVT_BUTTON, self.OnButtonSaveSendClick )
		self.button_Reset.Bind( wx.EVT_BUTTON, self.OnButtonResetClick )
		self.button_Cancel.Bind( wx.EVT_BUTTON, self.OnButtonCancelClick )
	
	def __del__( self ):
		pass
	
	
	# Virtual event handlers, overide them in your derived class
	def OnDialogCloseClick( self, event ):
		event.Skip()
	
	def OnDataTimeSelect( self, event ):
		event.Skip()
	
	def OnSendTo( self, event ):
		event.Skip()
	
	def OnCopyTo( self, event ):
		event.Skip()
	
	def OnButtonCopyReportClick( self, event ):
		event.Skip()
	
	def OnButtonSaveSendClick( self, event ):
		event.Skip()
	
	def OnButtonResetClick( self, event ):
		event.Skip()
	
	def OnButtonCancelClick( self, event ):
		event.Skip()
	

###########################################################################
## Class DisplayAllDepartmentsDialogBase
###########################################################################

class DisplayAllDepartmentsDialogBase ( wx.Dialog ):
	
	def __init__( self, parent ):
		wx.Dialog.__init__ ( self, parent, id = wx.ID_ANY, title = u"请选择单位", pos = wx.DefaultPosition, size = wx.Size( 490,299 ), style = wx.DEFAULT_DIALOG_STYLE )
		
		self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
		
		boxSizer_VTopSizer = wx.BoxSizer( wx.VERTICAL )
		
		bSizer33 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.treeCtrl_AllDepartments = wx.TreeCtrl( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TR_DEFAULT_STYLE|wx.TR_EXTENDED|wx.TR_MULTIPLE|wx.VSCROLL )
		bSizer33.Add( self.treeCtrl_AllDepartments, 1, wx.ALL|wx.EXPAND, 5 )
		
		bSizer35 = wx.BoxSizer( wx.VERTICAL )
		
		
		bSizer35.AddSpacer( ( 0, 0), 1, wx.EXPAND, 5 )
		
		self.button_Add = wx.Button( self, wx.ID_ANY, u">>>>", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer35.Add( self.button_Add, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		bSizer35.AddSpacer( ( 0, 0), 1, wx.EXPAND, 5 )
		
		self.button_Remove = wx.Button( self, wx.ID_ANY, u"<<<<", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer35.Add( self.button_Remove, 0, wx.ALL, 5 )
		
		
		bSizer35.AddSpacer( ( 0, 0), 1, wx.EXPAND, 5 )
		
		
		bSizer33.Add( bSizer35, 0, wx.EXPAND|wx.ALL, 5 )
		
		listBox_SelectedChoices = []
		self.listBox_Selected = wx.ListBox( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, listBox_SelectedChoices, 0 )
		bSizer33.Add( self.listBox_Selected, 0, wx.ALL|wx.EXPAND, 5 )
		
		
		boxSizer_VTopSizer.Add( bSizer33, 1, wx.EXPAND, 5 )
		
		boxSizer_HCommands = wx.BoxSizer( wx.HORIZONTAL )
		
		
		boxSizer_HCommands.AddSpacer( ( 0, 0), 1, wx.EXPAND, 5 )
		
		self.button_OK = wx.Button( self, wx.ID_ANY, u"确定", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.button_OK.SetDefault() 
		boxSizer_HCommands.Add( self.button_OK, 0, wx.ALL, 5 )
		
		self.button_Reset = wx.Button( self, wx.ID_ANY, u"重置", wx.DefaultPosition, wx.DefaultSize, 0 )
		boxSizer_HCommands.Add( self.button_Reset, 0, wx.ALL, 5 )
		
		
		boxSizer_VTopSizer.Add( boxSizer_HCommands, 0, wx.EXPAND|wx.TOP|wx.BOTTOM, 5 )
		
		
		self.SetSizer( boxSizer_VTopSizer )
		self.Layout()
		
		self.Centre( wx.BOTH )
		
		# Connect Events
		self.Bind( wx.EVT_CLOSE, self.OnDialogClose )
		self.button_Add.Bind( wx.EVT_BUTTON, self.OnAddButtonClick )
		self.button_Remove.Bind( wx.EVT_BUTTON, self.OnRemoveButtonClick )
		self.button_OK.Bind( wx.EVT_BUTTON, self.OnButtonOKClick )
		self.button_Reset.Bind( wx.EVT_BUTTON, self.OnButtonResetClick )
	
	def __del__( self ):
		pass
	
	
	# Virtual event handlers, overide them in your derived class
	def OnDialogClose( self, event ):
		event.Skip()
	
	def OnAddButtonClick( self, event ):
		event.Skip()
	
	def OnRemoveButtonClick( self, event ):
		event.Skip()
	
	def OnButtonOKClick( self, event ):
		event.Skip()
	
	def OnButtonResetClick( self, event ):
		event.Skip()
	

###########################################################################
## Class DisplayQueryDialog
###########################################################################

class DisplayQueryDialog ( wx.Dialog ):
	
	def __init__( self, parent ):
		wx.Dialog.__init__ ( self, parent, id = wx.ID_ANY, title = wx.EmptyString, pos = wx.DefaultPosition, size = wx.Size( 510,247 ), style = wx.DEFAULT_DIALOG_STYLE )
		
		self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
		
		boxSizer_VTopSizer = wx.BoxSizer( wx.VERTICAL )
		
		
		self.SetSizer( boxSizer_VTopSizer )
		self.Layout()
		
		self.Centre( wx.BOTH )
	
	def __del__( self ):
		pass
	

###########################################################################
## Class MainFrameBase
###########################################################################

class MainFrameBase ( wx.Frame ):
	
	def __init__( self, parent ):
		wx.Frame.__init__ ( self, parent, id = wx.ID_ANY, title = u"Police Telegram Assistant", pos = wx.DefaultPosition, size = wx.Size( 800,600 ), style = wx.DEFAULT_FRAME_STYLE|wx.TAB_TRAVERSAL )
		
		self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
		
		bSizer23 = wx.BoxSizer( wx.VERTICAL )
		
		self.notebook_MainNotenook = wx.Notebook( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, 0 )
		self.panel_Inbox = wx.Panel( self.notebook_MainNotenook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer25 = wx.BoxSizer( wx.VERTICAL )
		
		self.listCtrl_Inbox = wx.ListCtrl( self.panel_Inbox, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.LC_REPORT )
		bSizer25.Add( self.listCtrl_Inbox, 1, wx.ALL|wx.EXPAND, 5 )
		
		self.m_button10 = wx.Button( self.panel_Inbox, wx.ID_ANY, u"导出已收电报", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer25.Add( self.m_button10, 0, wx.ALL, 5 )
		
		
		self.panel_Inbox.SetSizer( bSizer25 )
		self.panel_Inbox.Layout()
		bSizer25.Fit( self.panel_Inbox )
		self.notebook_MainNotenook.AddPage( self.panel_Inbox, u"收报箱", False )
		self.panel_Outbox = wx.Panel( self.notebook_MainNotenook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer26 = wx.BoxSizer( wx.VERTICAL )
		
		self.m_button11 = wx.Button( self.panel_Outbox, wx.ID_ANY, u"写电报", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer26.Add( self.m_button11, 0, wx.ALL, 5 )
		
		self.listCtrl_Outbox = wx.ListCtrl( self.panel_Outbox, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.LC_REPORT )
		bSizer26.Add( self.listCtrl_Outbox, 1, wx.ALL|wx.EXPAND, 5 )
		
		self.m_button12 = wx.Button( self.panel_Outbox, wx.ID_ANY, u"导出已发电报", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer26.Add( self.m_button12, 0, wx.ALL, 5 )
		
		
		self.panel_Outbox.SetSizer( bSizer26 )
		self.panel_Outbox.Layout()
		bSizer26.Fit( self.panel_Outbox )
		self.notebook_MainNotenook.AddPage( self.panel_Outbox, u"发报箱", True )
		self.panel_SystemSetting = wx.Panel( self.notebook_MainNotenook, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		self.notebook_MainNotenook.AddPage( self.panel_SystemSetting, u"系统设置", False )
		
		bSizer23.Add( self.notebook_MainNotenook, 1, wx.EXPAND |wx.ALL, 5 )
		
		
		self.SetSizer( bSizer23 )
		self.Layout()
		
		self.Centre( wx.BOTH )
		
		# Connect Events
		self.m_button11.Bind( wx.EVT_BUTTON, self.OnEditNew )
	
	def __del__( self ):
		pass
	
	
	# Virtual event handlers, overide them in your derived class
	def OnEditNew( self, event ):
		event.Skip()
	

###########################################################################
## Class LoginDialogBase
###########################################################################

class LoginDialogBase ( wx.Dialog ):
	
	def __init__( self, parent ):
		wx.Dialog.__init__ ( self, parent, id = wx.ID_ANY, title = u"请登陆", pos = wx.DefaultPosition, size = wx.Size( 380,175 ), style = wx.CAPTION )
		
		self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
		
		bSizer25 = wx.BoxSizer( wx.VERTICAL )
		
		self.m_staticText10 = wx.StaticText( self, wx.ID_ANY, u"公安密传电报助手", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText10.Wrap( -1 )
		self.m_staticText10.SetFont( wx.Font( 9, 74, 90, 92, False, wx.EmptyString ) )
		
		bSizer25.Add( self.m_staticText10, 0, wx.ALL|wx.EXPAND, 5 )
		
		bSizer26 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.m_staticText11 = wx.StaticText( self, wx.ID_ANY, u"账号：", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText11.Wrap( -1 )
		bSizer26.Add( self.m_staticText11, 0, wx.EXPAND|wx.ALL, 5 )
		
		self.textCtrl_UserName = wx.TextCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer26.Add( self.textCtrl_UserName, 0, wx.ALL, 5 )
		
		
		bSizer25.Add( bSizer26, 1, wx.EXPAND, 5 )
		
		bSizer27 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.m_staticText12 = wx.StaticText( self, wx.ID_ANY, u"密码：", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText12.Wrap( -1 )
		bSizer27.Add( self.m_staticText12, 0, wx.ALL, 5 )
		
		self.textCtrl_Password = wx.TextCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.TE_PASSWORD )
		bSizer27.Add( self.textCtrl_Password, 0, wx.ALL, 5 )
		
		
		bSizer25.Add( bSizer27, 1, wx.EXPAND, 5 )
		
		bSizer28 = wx.BoxSizer( wx.HORIZONTAL )
		
		self.button_Login = wx.Button( self, wx.ID_ANY, u"登陆", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer28.Add( self.button_Login, 0, wx.ALL, 5 )
		
		self.button_Quit = wx.Button( self, wx.ID_ANY, u"退出", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer28.Add( self.button_Quit, 0, wx.ALL, 5 )
		
		
		bSizer25.Add( bSizer28, 1, wx.EXPAND, 5 )
		
		
		self.SetSizer( bSizer25 )
		self.Layout()
		
		self.Centre( wx.BOTH )
		
		# Connect Events
		self.button_Login.Bind( wx.EVT_BUTTON, self.OnButtonClickLogin )
		self.button_Quit.Bind( wx.EVT_BUTTON, self.OnButtonClickQuit )
	
	def __del__( self ):
		pass
	
	
	# Virtual event handlers, overide them in your derived class
	def OnButtonClickLogin( self, event ):
		event.Skip()
	
	def OnButtonClickQuit( self, event ):
		event.Skip()
	

###########################################################################
## Class SendingDialogBase
###########################################################################

class SendingDialogBase ( wx.Dialog ):
	
	def __init__( self, parent ):
		wx.Dialog.__init__ ( self, parent, id = wx.ID_ANY, title = u"发送中...", pos = wx.DefaultPosition, size = wx.Size( 400,300 ), style = wx.CAPTION|wx.STAY_ON_TOP )
		
		self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
		
		boxSizer_VTopSizer = wx.BoxSizer( wx.VERTICAL )
		
		self.gauge_SendingStatus = wx.Gauge( self, wx.ID_ANY, 100, wx.DefaultPosition, wx.DefaultSize, wx.GA_HORIZONTAL )
		self.gauge_SendingStatus.SetValue( 0 ) 
		boxSizer_VTopSizer.Add( self.gauge_SendingStatus, 0, wx.ALL|wx.EXPAND, 5 )
		
		self.textCtrl_SendingLog = wx.TextCtrl( self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, wx.TE_MULTILINE|wx.TE_READONLY )
		boxSizer_VTopSizer.Add( self.textCtrl_SendingLog, 1, wx.ALL|wx.EXPAND, 5 )
		
		self.button_Cancel = wx.Button( self, wx.ID_ANY, u"取消", wx.DefaultPosition, wx.DefaultSize, 0 )
		boxSizer_VTopSizer.Add( self.button_Cancel, 0, wx.ALL|wx.ALIGN_RIGHT, 5 )
		
		
		self.SetSizer( boxSizer_VTopSizer )
		self.Layout()
		
		self.Centre( wx.BOTH )
		
		# Connect Events
		self.button_Cancel.Bind( wx.EVT_BUTTON, self.OnCancelClick )
	
	def __del__( self ):
		pass
	
	
	# Virtual event handlers, overide them in your derived class
	def OnCancelClick( self, event ):
		event.Skip()
	


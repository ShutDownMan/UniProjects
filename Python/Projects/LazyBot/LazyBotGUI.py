#!/usr/bin/env python
from __future__ import unicode_literals
# -*- coding: utf-8 -*- 

###########################################################################
## Python code generated with wxFormBuilder (version Jun 17 2015)
## http://www.wxformbuilder.org/
##
## PLEASE DO "NOT" EDIT THIS FILE!
###########################################################################

import wx
import wx.xrc

###########################################################################
## Class MainFrame
###########################################################################

class MainFrame ( wx.Frame ):
	
	def __init__( self, parent ):
		wx.Frame.__init__ ( self, parent, id = wx.ID_ANY, title = u"LazyBot GUI", pos = wx.DefaultPosition, size = wx.Size( 669,535 ), style = wx.DEFAULT_FRAME_STYLE|wx.RESIZE_BORDER|wx.TAB_TRAVERSAL )
		
		self.SetSizeHintsSz( wx.DefaultSize, wx.DefaultSize )
		
		self.m_menubar1 = wx.MenuBar( 0 )
		self.m_menu1 = wx.Menu()
		self.m_menu11 = wx.Menu()
		self.m_menu1.AppendSubMenu( self.m_menu11, u"MyMenu" )
		
		self.m_menubar1.Append( self.m_menu1, u"MyMenu" ) 
		
		self.SetMenuBar( self.m_menubar1 )
		
		fgSizer2 = wx.FlexGridSizer( 0, 2, 0, 0 )
		fgSizer2.SetFlexibleDirection( wx.BOTH )
		fgSizer2.SetNonFlexibleGrowMode( wx.FLEX_GROWMODE_SPECIFIED )
		
		gSizer1 = wx.GridSizer( 0, 2, 0, 0 )
		
		self.m_panel1 = wx.Panel( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.SIMPLE_BORDER|wx.TAB_TRAVERSAL )
		fgSizer3 = wx.FlexGridSizer( 0, 2, 0, 0 )
		fgSizer3.SetFlexibleDirection( wx.BOTH )
		fgSizer3.SetNonFlexibleGrowMode( wx.FLEX_GROWMODE_SPECIFIED )
		
		bSizer511 = wx.BoxSizer( wx.VERTICAL )
		
		self.usernameLabel11 = wx.StaticText( self.m_panel1, wx.ID_ANY, u"Username:", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.usernameLabel11.Wrap( -1 )
		bSizer511.Add( self.usernameLabel11, 0, wx.ALL|wx.EXPAND, 5 )
		
		self.username_input = wx.TextCtrl( self.m_panel1, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer511.Add( self.username_input, 0, wx.ALL, 5 )
		
		self.m_staticText321 = wx.StaticText( self.m_panel1, wx.ID_ANY, u"Password:", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText321.Wrap( -1 )
		bSizer511.Add( self.m_staticText321, 0, wx.ALL, 5 )
		
		self.password_input = wx.TextCtrl( self.m_panel1, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer511.Add( self.password_input, 0, wx.ALL, 5 )
		
		
		fgSizer3.Add( bSizer511, 1, wx.EXPAND, 5 )
		
		self.m_panel9 = wx.Panel( self.m_panel1, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		fgSizer3.Add( self.m_panel9, 1, wx.EXPAND |wx.ALL, 0 )
		
		self.m_panel10 = wx.Panel( self.m_panel1, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		fgSizer3.Add( self.m_panel10, 1, wx.EXPAND |wx.ALL, 0 )
		
		self.add_account_btn = wx.Button( self.m_panel1, wx.ID_ANY, u"Add", wx.DefaultPosition, wx.DefaultSize, 0 )
		fgSizer3.Add( self.add_account_btn, 0, wx.ALIGN_BOTTOM|wx.ALIGN_RIGHT|wx.ALL, 5 )
		
		
		self.m_panel1.SetSizer( fgSizer3 )
		self.m_panel1.Layout()
		fgSizer3.Fit( self.m_panel1 )
		gSizer1.Add( self.m_panel1, 1, wx.EXPAND |wx.ALL, 0 )
		
		self.m_panel6 = wx.Panel( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.SIMPLE_BORDER|wx.TAB_TRAVERSAL )
		bSizer31 = wx.BoxSizer( wx.VERTICAL )
		
		self.m_staticText311 = wx.StaticText( self.m_panel6, wx.ID_ANY, u"Search Coords:", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText311.Wrap( -1 )
		bSizer31.Add( self.m_staticText311, 0, wx.ALL|wx.EXPAND, 5 )
		
		fgSizer5 = wx.FlexGridSizer( 0, 2, 0, 0 )
		fgSizer5.SetFlexibleDirection( wx.BOTH )
		fgSizer5.SetNonFlexibleGrowMode( wx.FLEX_GROWMODE_SPECIFIED )
		
		fgSizer51 = wx.FlexGridSizer( 0, 2, 0, 0 )
		fgSizer51.SetFlexibleDirection( wx.BOTH )
		fgSizer51.SetNonFlexibleGrowMode( wx.FLEX_GROWMODE_SPECIFIED )
		
		self.m_staticText13 = wx.StaticText( self.m_panel6, wx.ID_ANY, u"X:", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText13.Wrap( -1 )
		fgSizer51.Add( self.m_staticText13, 0, wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_CENTER_VERTICAL|wx.ALL, 2 )
		
		self.m_textCtrl31 = wx.TextCtrl( self.m_panel6, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.Size( 50,-1 ), 0 )
		self.m_textCtrl31.SetMinSize( wx.Size( 50,-1 ) )
		
		fgSizer51.Add( self.m_textCtrl31, 0, wx.ALL, 5 )
		
		
		fgSizer5.Add( fgSizer51, 1, wx.EXPAND, 5 )
		
		fgSizer511 = wx.FlexGridSizer( 0, 2, 0, 0 )
		fgSizer511.SetFlexibleDirection( wx.BOTH )
		fgSizer511.SetNonFlexibleGrowMode( wx.FLEX_GROWMODE_SPECIFIED )
		
		self.m_staticText14 = wx.StaticText( self.m_panel6, wx.ID_ANY, u"Y:", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText14.Wrap( -1 )
		fgSizer511.Add( self.m_staticText14, 0, wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_CENTER_VERTICAL|wx.ALL, 2 )
		
		self.m_textCtrl311 = wx.TextCtrl( self.m_panel6, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.Size( 50,-1 ), 0 )
		self.m_textCtrl311.SetMinSize( wx.Size( 50,-1 ) )
		
		fgSizer511.Add( self.m_textCtrl311, 0, wx.ALL, 5 )
		
		
		fgSizer5.Add( fgSizer511, 1, wx.EXPAND, 5 )
		
		
		bSizer31.Add( fgSizer5, 0, wx.EXPAND, 5 )
		
		fgSizer15 = wx.FlexGridSizer( 0, 2, 0, 0 )
		fgSizer15.SetFlexibleDirection( wx.BOTH )
		fgSizer15.SetNonFlexibleGrowMode( wx.FLEX_GROWMODE_SPECIFIED )
		
		self.m_staticText7 = wx.StaticText( self.m_panel6, wx.ID_ANY, u"Add Barbarian", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText7.Wrap( -1 )
		fgSizer15.Add( self.m_staticText7, 0, wx.ALL, 5 )
		
		self.m_panel25 = wx.Panel( self.m_panel6, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		fgSizer15.Add( self.m_panel25, 1, wx.EXPAND |wx.ALL, 5 )
		
		self.add_barbarian_input = wx.TextCtrl( self.m_panel6, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		self.add_barbarian_input.SetMinSize( wx.Size( 140,-1 ) )
		
		fgSizer15.Add( self.add_barbarian_input, 0, wx.ALL, 5 )
		
		self.m_panel26 = wx.Panel( self.m_panel6, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		fgSizer15.Add( self.m_panel26, 1, wx.EXPAND |wx.ALL, 5 )
		
		self.m_panel27 = wx.Panel( self.m_panel6, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		fgSizer15.Add( self.m_panel27, 1, wx.EXPAND |wx.ALL, 5 )
		
		self.add_barbarian = wx.Button( self.m_panel6, wx.ID_ANY, u"Add", wx.DefaultPosition, wx.DefaultSize, 0 )
		fgSizer15.Add( self.add_barbarian, 0, wx.ALL, 5 )
		
		
		bSizer31.Add( fgSizer15, 1, wx.EXPAND, 5 )
		
		
		self.m_panel6.SetSizer( bSizer31 )
		self.m_panel6.Layout()
		bSizer31.Fit( self.m_panel6 )
		gSizer1.Add( self.m_panel6, 1, wx.EXPAND |wx.ALL, 0 )
		
		self.m_panel911 = wx.Panel( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.SIMPLE_BORDER|wx.TAB_TRAVERSAL )
		bSizer6 = wx.BoxSizer( wx.VERTICAL )
		
		self.m_staticText10 = wx.StaticText( self.m_panel911, wx.ID_ANY, u"Accounts", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText10.Wrap( -1 )
		bSizer6.Add( self.m_staticText10, 0, wx.ALL, 5 )
		
		account_choiceChoices = [ u"-- Select Your Account --", u"Account1", u"Account2", u"Account3", u"Account4" ]
		self.account_choice = wx.Choice( self.m_panel911, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, account_choiceChoices, wx.CB_SORT )
		self.account_choice.SetSelection( 0 )
		bSizer6.Add( self.account_choice, 0, wx.ALL, 5 )
		
		
		self.m_panel911.SetSizer( bSizer6 )
		self.m_panel911.Layout()
		bSizer6.Fit( self.m_panel911 )
		gSizer1.Add( self.m_panel911, 1, wx.EXPAND |wx.ALL, 0 )
		
		self.m_panel19 = wx.Panel( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.SIMPLE_BORDER )
		bSizer9 = wx.BoxSizer( wx.VERTICAL )
		
		fgSizer31 = wx.FlexGridSizer( 0, 2, 0, 0 )
		fgSizer31.SetFlexibleDirection( wx.BOTH )
		fgSizer31.SetNonFlexibleGrowMode( wx.FLEX_GROWMODE_SPECIFIED )
		
		self.m_staticText12 = wx.StaticText( self.m_panel19, wx.ID_ANY, u"Add Village:", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText12.Wrap( -1 )
		fgSizer31.Add( self.m_staticText12, 1, wx.ALL|wx.EXPAND, 5 )
		
		self.m_panel20 = wx.Panel( self.m_panel19, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		fgSizer31.Add( self.m_panel20, 1, wx.EXPAND |wx.ALL, 0 )
		
		self.add_village_input = wx.TextCtrl( self.m_panel19, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.DefaultSize, 0 )
		fgSizer31.Add( self.add_village_input, 1, wx.ALL|wx.EXPAND, 5 )
		
		self.m_panel21 = wx.Panel( self.m_panel19, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		fgSizer31.Add( self.m_panel21, 1, wx.ALL|wx.EXPAND, 0 )
		
		self.m_panel22 = wx.Panel( self.m_panel19, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		fgSizer31.Add( self.m_panel22, 1, wx.EXPAND |wx.ALL, 0 )
		
		self.add_village_btn = wx.Button( self.m_panel19, wx.ID_ANY, u"Add", wx.DefaultPosition, wx.DefaultSize, 0 )
		fgSizer31.Add( self.add_village_btn, 1, wx.ALL|wx.EXPAND, 5 )
		
		
		bSizer9.Add( fgSizer31, 0, wx.ALL|wx.EXPAND|wx.ALIGN_CENTER_HORIZONTAL, 0 )
		
		self.m_button5 = wx.Button( self.m_panel19, wx.ID_ANY, u"Find Villages From Account", wx.DefaultPosition, wx.DefaultSize, 0 )
		bSizer9.Add( self.m_button5, 0, wx.ALL|wx.EXPAND|wx.SHAPED, 5 )
		
		
		self.m_panel19.SetSizer( bSizer9 )
		self.m_panel19.Layout()
		bSizer9.Fit( self.m_panel19 )
		gSizer1.Add( self.m_panel19, 1, wx.ALL|wx.EXPAND, 0 )
		
		self.add_account = wx.Panel( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.SIMPLE_BORDER|wx.TAB_TRAVERSAL )
		fgSizer8 = wx.FlexGridSizer( 0, 2, 0, 0 )
		fgSizer8.SetFlexibleDirection( wx.BOTH )
		fgSizer8.SetNonFlexibleGrowMode( wx.FLEX_GROWMODE_SPECIFIED )
		
		self.m_staticText9 = wx.StaticText( self.add_account, wx.ID_ANY, u"Bot Status: ???", wx.DefaultPosition, wx.DefaultSize, 0 )
		self.m_staticText9.Wrap( -1 )
		fgSizer8.Add( self.m_staticText9, 0, wx.ALL, 5 )
		
		self.m_panel15 = wx.Panel( self.add_account, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		fgSizer8.Add( self.m_panel15, 1, wx.EXPAND |wx.ALL, 5 )
		
		self.m_button6 = wx.Button( self.add_account, wx.ID_ANY, u"Start Bot", wx.DefaultPosition, wx.DefaultSize, 0 )
		fgSizer8.Add( self.m_button6, 0, wx.ALL, 5 )
		
		self.stop_bot = wx.Button( self.add_account, wx.ID_ANY, u"Stop Bot", wx.DefaultPosition, wx.DefaultSize, 0 )
		fgSizer8.Add( self.stop_bot, 0, wx.ALL, 5 )
		
		
		self.add_account.SetSizer( fgSizer8 )
		self.add_account.Layout()
		fgSizer8.Fit( self.add_account )
		gSizer1.Add( self.add_account, 1, wx.EXPAND |wx.ALL, 0 )
		
		self.m_panel5 = wx.Panel( self, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, wx.TAB_TRAVERSAL )
		bSizer21 = wx.BoxSizer( wx.VERTICAL )
		
		villages_listChoices = [ u"0x00 - Village", u"0x01 - Village", u"0x01 - Village", u"0x01 - Village", u"0x03 - Village", u"0x02 - Village" ]
		self.villages_list = wx.ListBox( self.m_panel5, wx.ID_ANY, wx.DefaultPosition, wx.DefaultSize, villages_listChoices, wx.LB_MULTIPLE|wx.LB_NEEDED_SB|wx.LB_SORT )
		bSizer21.Add( self.villages_list, 1, wx.EXPAND, 5 )
		
		
		self.m_panel5.SetSizer( bSizer21 )
		self.m_panel5.Layout()
		bSizer21.Fit( self.m_panel5 )
		gSizer1.Add( self.m_panel5, 1, wx.EXPAND |wx.ALL, 0 )
		
		
		fgSizer2.Add( gSizer1, 1, wx.EXPAND, 5 )
		
		
		self.SetSizer( fgSizer2 )
		self.Layout()
		
		self.Centre( wx.BOTH )
		
		# Connect Events
		wx.CallAfter(self.username_input.Bind, wx.EVT_TEXT_ENTER, self.add_account )
		wx.CallAfter(self.password_input.Bind, wx.EVT_TEXT_ENTER, self.add_account )
		wx.CallAfter(self.add_account_btn.Bind, wx.EVT_BUTTON, self.add_account )
		wx.CallAfter(self.m_textCtrl31.Bind, wx.EVT_TEXT_ENTER, self.search_coord )
		wx.CallAfter(self.m_textCtrl311.Bind, wx.EVT_TEXT_ENTER, self.search_coord )
		wx.CallAfter(self.add_barbarian_input.Bind, wx.EVT_TEXT_ENTER, self.add_barbarian )
		wx.CallAfter(self.add_barbarian.Bind, wx.EVT_BUTTON, self.add_barbarian )
		wx.CallAfter(self.account_choice.Bind, wx.EVT_CHOICE, self.choose_account )
		wx.CallAfter(self.add_village_input.Bind, wx.EVT_TEXT_ENTER, self.add_village )
		wx.CallAfter(self.add_village_btn.Bind, wx.EVT_BUTTON, self.add_village )
		wx.CallAfter(self.m_button5.Bind, wx.EVT_BUTTON, self.find_all_villages_from_account )
		wx.CallAfter(self.m_button6.Bind, wx.EVT_BUTTON, self.start_bot )
		wx.CallAfter(self.villages_list.Bind, wx.EVT_LISTBOX_DCLICK, self.go_to_village )
	

	
	# Virtual event handlers, overide them in your derived class
	def add_account( self, event ):
		event.Skip()
	
	def search_coord( self, event ):
		event.Skip()
	
	
	def add_barbarian( self, event ):
		event.Skip()
	
	
	def choose_account( self, event ):
		event.Skip()
	
	def add_village( self, event ):
		event.Skip()
	
	
	def find_all_villages_from_account( self, event ):
		event.Skip()
	
	def start_bot( self, event ):
		event.Skip()
	
	def go_to_village( self, event ):
		event.Skip()
	

if __name__ == '__main__':
    app = wx.App(False)
    frame = MainFrame(parent=None)
    frame.Show()
    app.MainLoop()
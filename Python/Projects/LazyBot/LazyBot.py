# -*- coding: utf-8 -*-
from __future__ import unicode_literals

#import wx
import os

#from LazyBotGUI import MainFrame
from classes.commands import Commands
from classes.dom import DOM
from classes.build_upgrader import Build_Upgrader
from classes.globe_map import Globe_Map
from classes.file_utils import File_Utils
from classes.game import Game
from classes.rallypoint import RallyPoint

class LazyBot():
	firefox_capabilities = None	# Needed to setup browser
	foxDriver = None			# Browser selenium driver
	page = None					# Module related to selenium elements
	cmd = None					# Module with main game commands
	upgrader = None				# Module with HeadQuarter related commands
	globe_map = None			# Module with coord searching related commands
	ufile = None				# Module with file related functions
	game = None					# Module with misc game related commands
	rallypoint = None			# Module with Rally Point related commands

	Bot_Dir = os.getcwd()

	def __init__(self):
		self.cmd = Commands(self)
		self.page = DOM(self)
		self.upgrader = Build_Upgrader(self)
		self.globe_map = Globe_Map(self)
		self.ufile = File_Utils(self)
		self.game = Game(self)
		self.rallypoint = RallyPoint(self)
	#	self.start_bot()
		

	def start_bot(self):
		self.cmd.open_game('','')
		self.globe_map.Search_Coords()
	#	self.rallypoint.create_predefinitions()
	#	self.globe_map.Search_Coords()
		pass

	def search_coord(self, event):
		self.globe_map.Search_Coords((str(MainFrame.coord_x.get_attribute('value')), str(MainFrame.coord_y.get_attribute('value'))))

if __name__ == "__main__":
#	app = wx.App(False)
#	frame = MainFrame(parent=None)
#	frame.Show()
#	app.MainLoop()
#	bot = LazyBot()
	pass

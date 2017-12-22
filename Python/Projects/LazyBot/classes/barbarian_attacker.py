# -*- coding: utf-8 -*-
from __future__ import unicode_literals
from selenium.webdriver.common.keys import Keys

from css_paths import CSS_Paths as paths
from relative_paths import Relative_Paths as relative

class Barbarian_Attacker:

	Master = None

	def __init__(self, master):
		self.Master = master
		print "Barbarian_Attacker module loaded!\n" + str(master)

	def Attack_Nearest_Barbarians(self, village=''):
		troopsToSend = self.checkTroops()
		self.Master.page.sendKeys(Keys.ESCAPE)

		if troopsToSend == '':
			print "No troops no farming =/"
			return

		barbVillages = self.Master.ufile.get_file_array(self.Master.Bot_Dir + '\\Game\\LazyShut\\Poenari\\Villages\\0x00 - Village\\Barbarians.txt')

		attacks = self.Master.ufile.get_file_array(self.Master.Bot_Dir + '\\Game\\LazyShut\\Poenari\\Configs\\Gobal Attacks List.txt')


	def check_troops(self):
		canvas = self.Master.page.get_elem(paths.Map_Canvas)
		self.Master.page.sendKeys(Keys.ESCAPE)
		self.Master.page.Type(canvas, "R")


	def get_current_village(self):
		pass



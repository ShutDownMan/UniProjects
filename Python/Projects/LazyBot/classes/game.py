# -*- coding: utf-8 -*-
from __future__ import unicode_literals

import time

from selenium.webdriver.common.keys import Keys

from css_paths import CSS_Paths as paths
from relative_paths import Relative_Paths as relative

class Game():

	Master = None

	def __init__(self, master):
		self.Master = master
		print "Game module loaded!\n" + str(master)
	def wait(self, how_much):
		time.sleep(how_much)

	def select_game(self, canvas=None):
		if canvas == None:
			canvas = self.Master.page.get_elem(paths.Map_Canvas)
		canvas.click()
		self.Master.page.sendKeys(canvas, Keys.ESCAPE)


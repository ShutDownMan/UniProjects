# -*- coding: utf-8 -*-
from __future__ import unicode_literals
from selenium import webdriver
from selenium.webdriver.common.desired_capabilities import DesiredCapabilities

from css_paths import CSS_Paths as paths

""" Where will be all the Start/Stop/Restart commands """
class Commands():

	Master = None

	
	def __init__(self, master):
		self.Master = master
	#	self.setupBrowser()


	""" Open Browser """

	def setupBrowser(self):

		self.Master.firefox_capabilities = DesiredCapabilities.FIREFOX
		self.Master.firefox_capabilities['marionette'] = True
		self.Master.foxDriver = webdriver.Firefox(capabilities=self.Master.firefox_capabilities)
		self.Master.foxDriver.set_page_load_timeout(30)

	""" Open Game """

	def open_game(self, username, password):

		""" Start Browser """
		if self.Master.foxDriver == None:
			self.setupBrowser()


		""" First Login Page """
		loaded = False
		while loaded == False:
			try:
				self.Master.foxDriver.get("https://br.tribalwars2.com/")
				loaded = True
			except:
				print "Page didn't load properly\n"
				# loaded stay false

		self.Master.page.WaitToLoadCSS(paths.Misc_Logo)


		""" Login related """
		css_username = self.Master.page.FindElem(paths.Login_Username)
		css_password = self.Master.page.FindElem(paths.Login_Password)
		css_button = self.Master.page.FindElem(paths.Login_Button)

		if css_username != None and self.Master.page.FindElemAttribute(css_username, "ng-model", "loginUsername") == True:
			self.Master.page.Type(css_username, "LazyShut")

		if css_password != None and self.Master.page.FindElemAttribute(css_password, "ng-model", "loginPassword") == True:
			self.Master.page.Type(css_password, "RTA402015")

		if css_button != None:
			css_button.click()


		""" World Selection Page """
		self.Master.page.WaitToLoadCSS(paths.Login_WorldsList, 20)

		firstWorld = self.Master.page.get_elem(paths.Login_FirstWorld)

		if firstWorld != None:
			firstWorld.click()


		""" Game Page """
		self.Master.page.WaitToLoadCSS(paths.Map_Canvas, 20)

		reward_button = self.Master.page.get_elem(paths.Misc_Collect_Reward)
		if reward_button != None:
			reward_button.click()



#if __name__ == "__main__":
#	cmd = Commands()	

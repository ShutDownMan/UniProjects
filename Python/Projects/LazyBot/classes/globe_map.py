# -*- coding: utf-8 -*-
from __future__ import unicode_literals


from selenium import webdriver

from css_paths import CSS_Paths as paths
from relative_paths import Relative_Paths as relative

# bot.globe_map = Globe_Map(bot)

class Globe_Map():

	Master = None

	def __init__(self, master):
		self.Master = master
		print "Globe Map class loaded!\n" + str(master)

	def Search_Coords(self, coords=(0,0)):
		globe_btn = self.Master.page.get_elem(paths.Globe_Button)
		globe_btn_parent = globe_btn.find_element_by_xpath('./..')
		globe_search = None
		globe_coord = None

		try:
			globe_coord = globe_btn_parent.find_element_by_xpath(relative.Globe_Coord)
	#		globe_coord = globe_coord.find_elements_by_xpath('./*')
		except:
			print "Search menu not open"

		attr = globe_btn_parent.find_element_by_xpath('././div[@id="world-map-search-wrapper"]')
		attr = attr.find_element_by_xpath('././div[1]').get_attribute("class")

		if "visible" not in attr:
			globe_btn.click()

		try:

			for i in range(30):
				globe_coord = globe_btn_parent.find_element_by_xpath(relative.Globe_Coord)
				if globe_coord != None:
					globe_coord = globe_coord.find_elements_by_xpath('./*')
					globe_search = globe_coord[2]
					break;
				self.Master.game.wait(.3)

		except:
			print "Couldn't search for coords: " + str(coords[0]) + "|" + str(coords[1])

		try:
			for a in range(2):
				for i in range(3):
					globe_coord[i] = globe_coord[i].find_element_by_xpath('./*')
		except:
			print "Couldn't explode list"


		globe_coord[0].clear()
		globe_coord[1].clear()

		self.Master.page.Type(globe_coord[0], str(coords[0]))
		self.Master.page.Type(globe_coord[1], str(coords[1]))

		globe_search.click()

		globe_btn.click()

		return True
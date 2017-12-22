# -*- coding: utf-8 -*-
from __future__ import unicode_literals
import io
from selenium.webdriver.common.keys import Keys

from css_paths import CSS_Paths as paths
from relative_paths import Relative_Paths as relative

Buildings =	{"HEAD QUARTER":	relative.Build_HeadQuarter,
			"TIMBER CAMP":		relative.Build_TimberCamp,
			"CLAY PIT":			relative.Build_ClayPit,
			"IRON MINE":		relative.Build_IronMine,
			"FARM":				relative.Build_Farm,
			"WAREHOUSE":		relative.Build_Warehouse,
			"RALLY POINT":		relative.Build_RallyPoint,
			"BARRACKS":			relative.Build_Barracks,
		#	"":paths.Build_
		#	"":paths.Build_
		#	"":paths.Build_
		#	"":paths.Build_
		#	"":paths.Build_
		#	"":paths.Build_
		#	"":paths.Build_
			"":					paths.Map_Canvas}

class Build_Upgrader():
	Master = None

	def __init__(self, master):
		self.Master = master
		print "Build Upgrader loaded!\n" + str(master)

	def check_green_mark(self):
		elem = self.Master.page.get_elem(paths.Build_Finish_Build)
		if elem != None:
			elem.click()
			print "Green Mark!"
		else:
			print "No Green Mark"

	def upgrade_building(self, building):
		canvas = self.Master.page.get_elem(paths.Map_Canvas)
		self.Master.game.select_game(canvas)
		self.Master.page.Type(canvas, "H")

		boxPaper = self.Master.page.FindElem(paths.Build_BoxPaper)
		if boxPaper != None:
			print "Building Menu loaded!"


		buildingBtn = boxPaper.find_element_by_xpath(Buildings[building.upper()])
		classAttr = self.Master.page.AttributeValue(buildingBtn, "class")
		btn_orange = len(classAttr)
		btn_grey = 0

		try:
			btn_orange = classAttr.index("btn-orange")
			btn_grey = classAttr.index("btn-grey")
		except:
			print "Error on upgrade buildings"

		self.Master.foxDriver.execute_script("return arguments[0].scrollIntoView();", buildingBtn)

		if buildingBtn != None and btn_orange > btn_grey:
			buildingBtn.click()
			print "Successfully upgraded building: " + building
		else:
			print "Couldn't upgrade building: " + building

	#	pagex = self.Master.page.get_elem(paths.Build_PageX)	
		self.Master.page.sendKeys(canvas, Keys.ESCAPE)


	def get_build_List(self, village):		
		file = io.open('..\\Villages\\0x00 - Village\\To Build.txt', "r")
		buildList = file.readlines()
		file.close()

		return buildList


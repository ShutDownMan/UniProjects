# -*- coding: utf-8 -*-
from __future__ import unicode_literals

import time
import collections

from css_paths import CSS_Paths as paths
from relative_paths import Relative_Paths as relative

units_quant_inputs = {
		"Spearman":		relative.RallyPoint_CreateSpearman,
		'Swordsman':	relative.RallyPoint_CreateSwordsman,
		'Viking':		relative.RallyPoint_CreateViking,
		'Archer':		relative.RallyPoint_CreateArcher,
		'Light Cv':		relative.RallyPoint_CreateLightCv,
		'Mnt Archer':	relative.RallyPoint_CreateMntArcher,
		'Heavy Cv':		relative.RallyPoint_CreateHeavyCv,
		'Berseker':		relative.RallyPoint_CreateBerseker
	}

class RallyPoint():

	Master = None

	def __init__(self, master):
		self.Master = master
		print "RallyPoint module loaded!\n" + str(master)

	def check_global_predefs(self):
		canvas = self.Master.page.get_elem(paths.Map_Canvas)
		self.Master.page.Type(canvas, "R")

		village_status = self.Master.ufile.get_status("[0x00 - Village]")

		units_ideal_division = self.calc_ideal_predef_division(self.current_unit_quant())

		undone_predefs = []

		for k,v in village_status.items():
			print k
			if k == 'Predefinitions':
				for unit, status in village_status[k].items():
					if 'None' in status:
						undone_predefs.append("[" + unit + " Farming" + "]")

		if len(undone_predefs) > 0:
			rally_menu = self.Master.page.FindElem(paths.RallyPoint_Menu)

			if rally_menu == None:
				print "Error on rally_menu when creating predefinition!"
				return

			global_predef_btn = rally_menu.find_element_by_xpath(relative.RallyPoint_ShowGlobal)

			global_predef_btn.click()

			global_predefs = self.Master.page.FindElem(paths.RallyPoint_Menu)

			if global_predefs == None:
				print "Error on global_predefs when creating predefinition!"
				return

			try:
				i = 1
				while True:
					current_predef = global_predefs.find_element_by_xpath(relative.RallyPoint_GlobalPredefName.replace('index', str(i)))

					toggle_btn = global_predefs.find_element_by_xpath(relative.RallyPoint_GlobalPredefToggle.replace('index', str(i)))

					for predef in undone_predefs:
						if predef in current_predef.text:
							toggle_btn.click()
							self.Master.ufile.update_status("[0x00 - Village]", unit, str(ideal_unit_quant))
							break

					for unit, v in units_quant_inputs.items():
						if "[" + unit + " Farming" + "]" in current_predef.text:
							if 'switch-off' in self.Master.page.AttributeValue(toggle_btn, "class"):
								print "I told you not to touch the default predefs!"
								toggle_btn.click()

				i += 1
			except:
				print "End of predef list!"
				pass


	def create_predefinitions(self):
		canvas = self.Master.page.get_elem(paths.Map_Canvas)
		self.Master.page.Type(canvas, "R")

		rally_menu = self.Master.page.FindElem(paths.RallyPoint_Menu)

		if rally_menu == None:
			print "Error on rally_menu when creating predefinition!"
			return

		village_status = self.Master.ufile.get_status("[0x00 - Village]")

		units_ideal_division = self.calc_ideal_predef_division(self.current_unit_quant())

		for k,v in village_status.items():
			print k
			if k == 'Predefinitions':
				for unit, status in village_status[k].items():
					if 'None' in status:
						ideal_unit_quant = 30
						self.create_predef(unit, rally_menu, ideal_unit_quant)
						self.Master.ufile.update_status("[0x00 - Village]", unit, str(ideal_unit_quant))

			self.Master.ufile.update_status("[0x00 - Village]", "PredefinitionsSetup", "True")



	def create_predef(self, unit, rally_menu=None, ideal_unit_quant=30):

		if rally_menu != None:
			create_predef_btn = rally_menu.find_element_by_xpath(relative.RallyPoint_CreatePredef)
			self.Master.foxDriver.execute_script("return arguments[0].scrollIntoView();", create_predef_btn)
			create_predef_btn.click()
			name_menu = self.Master.page.FindElem(paths.RallyPoint_NameMenu)
			if name_menu == None:
				print "Error on name_menu when creating predefinition!"
				return
			name_input = name_menu.find_element_by_xpath(relative.RallyPoint_NameInput)
			name_ok = name_menu.find_element_by_xpath(relative.RallyPoint_NameOK)

			self.Master.page.Type(name_input, ("[" + unit + " Farming" + "]"))
			name_ok.click()

			flag_menu = self.Master.page.FindElem(paths.RallyPoint_FlagCreating)

			if flag_menu == None:
				print "Error on flag_menu when creating predefinition!"
				return

			self.setup_flags((1,1,13), flag_menu)

			create_menu = self.Master.page.FindElem(paths.RallyPoint_CreateMenu)

			if create_menu == None:
				print "Error on create_menu when creating predefinition!"
				return

			closest_common = create_menu.find_element_by_xpath(relative.RallyPoint_ClosestCommon)

			units_inputs = closest_common.find_element_by_xpath(units_quant_inputs[unit])

			self.Master.page.Type(units_inputs, str(ideal_unit_quant))

			save_btn = create_menu.find_element_by_xpath(relative.RallyPoint_CreateSaveBtn)

			save_btn.click()



	def setup_flags(self, flag_order=(1,1,13), flag_menu=None):

		if flag_menu != None:
			flag_common = flag_menu.find_element_by_xpath(relative.RallyPoint_FlagCommon)
			for i in range(1,4):
				flag_path = (relative.RallyPoint_Buttons.replace('index', str(i)))
				print flag_path
				''' Determines shortest path to desired flag '''
				flag = flag_order[i-1]
				flag = flag = flag-1 if flag < 16-flag else -(16-flag)-1
				print flag

				if flag != 0:
					if flag > 0:
						up_btn = flag_common.find_element_by_xpath(flag_path.replace('jndex', '1'))
						# press up flag times
						for a in range(flag+1):
							up_btn.click()
							self.Master.game.wait(.3)
					else:
						down_btn = flag_common.find_element_by_xpath(flag_path.replace('jndex', '2'))
						# press down abs(flag) times
						for a in range(abs(flag)):
							down_btn.click()
							self.Master.game.wait(.3)

				flag_ok = flag_menu.find_element_by_xpath(relative.RallyPoint_OKButton)

				if flag_ok == None:
					print "Error on flag_ok when creating predefinition!"
					return

			flag_ok.click()


	def modify_predefinition(self, unit_to_modify,  new_quant=None, new_flag=None, new_name=None):
		canvas = self.Master.page.get_elem(paths.Map_Canvas)
		self.Master.page.Type(canvas, "R")

		rally_menu = self.Master.page.FindElem(paths.RallyPoint_Menu)

		if rally_menu == None:
			print "Error on rally_menu when creating predefinition!"
			return

		predefs = rally_menu.find_element_by_xpath(relative.RallyPoint_Predefs)

		predef_to_modify = None

		try:
			i = 1
			while True:
				current_predef = predefs.find_element_by_xpath(relative.RallyPoint_PredefName.replace('index', str(i)))

				if unit_to_modify in current_predef.text:
					predef_to_modify = current_predef

			i += 1
		except:
			print "End of predef list!"
			pass

		if current_predef != None:
			if new_quant != None:
				modify_btn = current_predef.find_element_by_xpath(relative.RallyPoint_EditPredef)
				modify_btn.click()

				create_menu = self.Master.page.FindElem(paths.RallyPoint_CreateMenu)

				if create_menu == None:
					print "Error on create_menu when creating predefinition!"
					return

				closest_common = create_menu.find_element_by_xpath(relative.RallyPoint_ClosestCommon)

				units_inputs = closest_common.find_element_by_xpath(units_quant_inputs[unit])

				self.Master.page.Type(units_inputs, str(new_quant))

				pass

		pass

	def calc_ideal_predef_division(self, troops=[0,0,0,0,0,0,0,0]):
		troops_cc = collections.OrderedDict()
		totalSumCC = 0

		troops_carrying_capacity = self.Master.ufile.get_config("Troops Carrying Capacity")
		i = 0
		for line in troops_carrying_capacity:
			m_stat = line.replace('\t','')
			m_stat = m_stat.strip()
			splited = m_stat.split('>')
			totalSumCC += int(splited[1])*troops[i]
			troops_cc.update({str(splited[0]):int(splited[1])})
			i += 1

		print 'Total carry capacity: ' + str(totalSumCC)+'\n----------'

		CCRationed = totalSumCC/float(50)
		print 'Ideal division per farm troop:\n' + str(CCRationed)+'\n----------'

		for k, v in troops_cc.items():
			if v > 0:
				quant = round(CCRationed/v)
				print k+'s Farm:\n'	+ str(quant)+'\n----------'

		return troops_cc


	def current_unit_quant(self):
		unit_bar = self.Master.page.get_elem(paths.UnitQuant_UnitBar)

		unit_bar_parent = unit_bar.find_element_by_xpath('./..')

		if "expanded" not in self.Master.page.AttributeValue(unit_bar_parent, "class"):
			unit_bar_btn = unit_bar.find_element_by_xpath(relative.UnitQuant_ToggleUnit)
			unit_bar_btn.click()
			self.Master.game.wait(1)

		unit_quant = [1,2,3,4,5,6,7,10]

		for i in range(8):
			unit_quant = unit_bar.find_element_by_xpath(relative.UnitQuant_UnitList.replace('index', str(unit_quant[i]))).text

			unit_quant[i] = int(unit_quant)

		return unit_quant


	def total_unit_quant(self):
		canvas = self.Master.page.get_elem(paths.Map_Canvas)
		self.Master.page.Type(canvas, "U")

		unit_menu = self.Master.page.FindElem(paths.UnitQuant_UnitMenu)

		if unit_menu == None:
			print "Error on unit_menu when creating predefinition!"
			return

		unit_quant = [1,2,3,4,5,6,7,10]
		
		for i in range(8):
			unit_quant = unit_menu.find_element_by_xpath(relative.UnitQuant_UnitHorizontal.replace('index', str(unit_quant[i]))).text

			unit_quant[i] = int(unit_quant)

		self.Master.game.select_game(unit_menu)

		return unit_quant


# bot.game.calc_ideal_predef_division(bot.game.current_unit_quant())

# Must remove
	def wait(self, how_much):
		time.sleep(how_much)
	def select_game(self, canvas=None):
		if canvas == None:
			canvas = self.Master.page.get_elem(paths.Map_Canvas)
		canvas.click()
		self.Master.page.sendKeys(canvas, Keys.ESCAPE)


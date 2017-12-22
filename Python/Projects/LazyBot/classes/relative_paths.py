# -*- coding: utf-8 -*-
from __future__ import unicode_literals


class Relative_Paths:

	# Globe related
	Globe_Coord =	"./div[@id='world-map-search-wrapper']/div/div/table[1]/tbody/tr[1]"

	# Build related
#	HQ_Main =			"./html/body/div[2]/section/div/div[2]/div[1]/div/div[2]/div[1]"
	Build_HeadQuarter =	"./div[1]/div/div/table/tbody/tr[4]/td[1]/span"
	Build_TimberCamp =	"./div[2]/div/div/table/tbody/tr[4]/td[1]/span"
	Build_ClayPit =		"./div[3]/div/div/table/tbody/tr[4]/td[1]/span"
	Build_IronMine =	"./div[4]/div/div/table/tbody/tr[4]/td[1]/span"
	Build_Farm =		"./div[5]/div/div/table/tbody/tr[4]/td[1]/span"
	Build_Warehouse =	"./div[6]/div/div/table/tbody/tr[4]/td[1]/span"
	Build_RallyPoint =	"./div[7]/div/div/table/tbody/tr[4]/td[1]/span"
	Build_Barracks =	"./div[8]/div/div/table/tbody/tr[4]/td[1]/span"


	# Rally Point related

#	RallyPoint_Menu =				"/html/body/div[2]/section/div/div[2]/div[1]"
	RallyPoint_NoPredef =			"./div/div[2]/div[1]/div[1]"
	RallyPoint_CreatePredef =		"./div/div[2]/div[2]/ul/li[1]/a"
	RallyPoint_ShowGlobal =			"./div/div[2]/div[2]/ul/li[2]/a"
#	RallyPoint_NameMenu =			"/html/body/div[5]/div/div/div/div"
	RallyPoint_NameInput =			"./div/div[1]/div/div[2]/input"
	RallyPoint_NameOK =				"./footer/ul/li/a"
#	RallyPoint_FlagCreating =		"./html/body/div[5]/div/div/div/div"
	RallyPoint_FlagLayers =			"./div/div[1]/div/div[2]/ul"
	RallyPoint_OKButton =			"./footer/ul/li[2]/a"
	RallyPoint_FlagCommon =			"./div/div[1]/div/div[2]"
	RallyPoint_Buttons =			"./ul/li[index]/a[jndex]"
#	RallyPoint_CreateOrModify =		"/html/body/div[5]/div/div/div/div"
	RallyPoint_ClosestCommon =		"./div/div[1]/div/table[3]/tbody"
	RallyPoint_CreateSpearman =		"./tr[1]/td[1]/div/input"
	RallyPoint_CreateSwordsman =	"./tr[1]/td[2]/div/input"
	RallyPoint_CreateViking =		"./tr[2]/td[1]/div/input"
	RallyPoint_CreateArcher =		"./tr[2]/td[2]/div/input"
	RallyPoint_CreateLightCv =		"./tr[3]/td[1]/div/input"
	RallyPoint_CreateMntArcher =	"./tr[3]/td[2]/div/input"
	RallyPoint_CreateHeavyCv =		"./tr[4]/td[1]/div/input"
	RallyPoint_CreateBerseker =		"./tr[5]/td[1]/div/input"
	RallyPoint_CreateSaveBtn =		"./footer/ul/li/a"
#	Predefinition info
	RallyPoint_Predefs =			"./div/div[2]/div[1]"
	RallyPoint_Available =			"./div[index]/table/tbody/tr[1]/td[1]/div/div/div"
	RallyPoint_PredefName =			"./div[index]/table/tbody/tr[1]/td[2]/span"
	RallyPoint_RecruitPredef =		"./div[index]/table/tbody/tr[2]/td[2]/a"
	RallyPoint_EditPredef =			"./div[index]/table/tbody/tr[1]/td[3]/a"
#	RallyPoint_ =					"/html/body/div[5]/div/div/div/div/div/div[1]/div/div[2]/table/tbody"
	RallyPoint_GlobalPredefName =	"/html/body/div[5]/div/div/div/div/div/div[1]/div/div[2]/table/tbody/tr[index]/td[1]/span"
	RallyPoint_GlobalPredefToggle =	"/html/body/div[5]/div/div/div/div/div/div[1]/div/div[2]/table/tbody/tr[index]/td[2]/div/div/div/div/span/span"

	# Units quantity related
#	UnitQuant_ =			"/html/body/div[2]/div[12]/div"
	UnitQuant_UnitList =	"./ul/li[index]/div/div"
	UnitQuant_ToggleUnit =	"./div/a"
#	UnitQuant_UnitMenu =		"/html/body/div[2]/section/div/div/div[1]/div[2]/div[2]/div/table/tbody/tr"
	UnitQuant_UnitHorizontal =	"./td[3+index]"

	# Village Dropdown related
#	VillageDropdown_Menu =		"/html/body/div[2]/div[11]/div[1]/div[2]/div[1]/div[2]/div[1]/div"
	VillageDropdown_Button =	"./a"
	VillageDropdown_Search =	"./div/div[1]/input"
	VillageDropdown_List =		"./div/div[2]/div[1]/div/table/tbody" # villages are tr
	VillageDropdown_Village =	"./tr[index]/td[2]/span[1]"
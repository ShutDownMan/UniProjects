# -*- coding: utf-8 -*-
from __future__ import unicode_literals
import io
import time
import fileinput
import win32api, win32con
import win32com.client
from os import remove, close, walk
from numpy import *
from PIL import Image, ImageGrab, ImageOps
from tempfile import mkstemp
from shutil import move


"""
Assumptions:
-----------------

# #All coordinates assume a screen resolution of 1920x1200, and Microsoft Edge 
# maximized with the Bookmarks Toolbar enabled.
# x_pad = -1
# y_pad = 114
# Play area =  x_pad+1, y_pad+1, 1920, 1045

"""


#Globals
#----------------------------

x_pad = -1
y_pad = -1










#End Globals
#-------------------------------------


class Cords:
	g_GatherBtn = (570, 465)
	g_newGather = (135, 765)

	r_RelatoryBtn = (705, 1110)
	r_OtherRels = (355, 265)
	r_BattleRels = (125, 265)

	c_GobalIcon = (570, 1117)
	c_xCordPos = (550, 980)
	c_yCordPos = (680, 980)
	c_GoBtn = (770, 980)
	c_ScreenCenter = (960, 600)

	h_MainB = (75, 475)
	h_Timber = (245, 475)
	h_Clay = (405, 475)
	h_Iron = (575, 475)
	h_Farm = (75, 730)
	h_Storage = (245, 730)
	h_Chapel = (405, 730)
	h_EnPoint = (575, 730)
	h_Barracks = (75, 980)
	h_Statue = (245, 980)
	h_Hospital = (405, 980)
	h_Wall = (575, 980)
	h_Market = (75, 725)
	h_Tavern = (245, 725)
	h_Academy = (405, 725)
	h_HofOrder = (575, 725)
	h_Scroll = (700, 795)

class Coords:
	Village_0x00 = (614, 595)

class Colors:
	g_NotLoaded = (184, 144, 100)


#-------------------------------------

def pressKeys(key=""):
	shell = win32com.client.Dispatch("WScript.Shell")
	shell.SendKeys(key)
	print "I pressed: " + key

def screenGrab():
	box = (x_pad+1, y_pad+1, x_pad+1920, y_pad+1200)
	im = ImageGrab.grab(box)
##	im.save(os.getcwd() + '\\Snap__' + str(int(time.time())) + '.png', 'PNG')
	return im

def grab(cords=(0,0,0,0)):
	im = ImageOps.grayscale(ImageGrab.grab(cords))
	a = array(im.getcolors())
	a = a.sum()
	print a
	return a

def leftClick(delay=.01):
	win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN,0,0)
	time.sleep(delay)
	win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP,0,0)
	print "Click."
##    time.sleep(.01)

def pointClick(cord=(0,0),delay=.01):
	mousePos(cord)
	leftClick(delay)


def middleClick():
	win32api.mouse_event(win32con.MOUSEEVENTF_WHEEL,0,0,120)
	time.sleep(1)
	win32api.mouse_event(win32con.MOUSEEVENTF_WHEEL,0,0,120)
	time.sleep(1)
	win32api.mouse_event(win32con.MOUSEEVENTF_MIDDLEUP,0,0)
	print "Click."
	time.sleep(.01)

def mClick():
	win32api.mouse_event(win32con.MOUSEEVENTF_ABSOLUTE,0,0)
	time.sleep(1)
	win32api.mouse_event(win32con.MOUSEEVENTF_ABSOLUTE,800,400)
	print "Click."
	time.sleep(.01)

def mousePos(cord=(0,0)):
	win32api.SetCursorPos(cord)
	print 'Mouse moved to: '+str(cord)


def get_cords():
	x,y = win32api.GetCursorPos()
##    x = x - x_pad
##    y = y - y_pad
	print x, y

def logIn():
	time.sleep(5)
	pointClick((1030, 185))
	pressKeys("ShutItDown")
	time.sleep(.1)
	pointClick((1155, 185))
	pressKeys("RTA402016")
	time.sleep(.1)
	pressKeys('{Enter}')
	time.sleep(5)
	pointClick((660, 645))

def checkBuildings():
	pointClick((1840, 315))

## 1840 315/ 370 = (187, 214, 86)


##----------------------------------##
## Attacking stuff

def checkRels():
	pointClick(Cords.r_RelatoryBtn, .5)	# Go to rels
	pointClick(Cords.r_OtherRels)		# Go to other rels
	pointClick(Cords.r_BattleRels, .5)	# Go to battle rels
	time.sleep(10)					# Waits
	if waitToLoad((400, 700),Colors.g_NotLoaded, False):	# Wait To load
		img = screenGrab()		# Gets screenshot
		troop = ''				# Troops var
		if img.getpixel((228, 254)) != (176, 140, 100): # (195, 182, 94): 	# Tests if new rels
			print "Novo relatório, mandar mesmas tropas"
		else:																# If not
			print "Nenhum novo relatório, esperar mais um pouco"
		i = 0
		for i in range(14):													# for each exclamation mark
			if img.getpixel((725, 1100)) != (68, 54, 41):					# If new Rel
				i = 0
			if img.getpixel((580, 421+(i*39))) == (182, 208, 47):			# Tests if green
				troops = checkTroops()
				print troops
				if troops == '':											# Check if enough troops
					break
				pointClick(r_RelatoryBtn, .5)								# Go to rels
				time.sleep(3)
				pointClick((580, 421+(i*39)))								# Go to exclamation
				wait(5)														# Waits
				if troops != '':
					pointClick((440, 888), .3)								# Go to enemy's village
					sendFarmTroops(troops)									# Send troops
					print "Send troops, again!"
			else:
				print "Do nothing"

		i = 0
		mousePos((700, 860))
		leftClick()
		time.sleep(3)
		img = screenGrab()
		for i in range(10):													# for each exclamation mark
			if img.getpixel((725, 1100)) != (68, 54, 41):					# If new Rel
				break
			if img.getpixel((580, 578+(i*39))) == (182, 208, 47):			# Tests if green
				troops = checkTroops()
				print troops
				if troops == '':											# Check if enough troops
					break
				mousePos(r_RelatoryBtn)										# Go to rels
				time.sleep(3)
				leftClick(.5)												# Click on it
				mousePos((700, 860))										# Page down
				leftClick()
				time.sleep(3)
				mousePos((580, 578+(i*39)))									# Go to exclamation
				leftClick()													# Clicks
				if troops != '':
					wait(5)													# Waits
					pointClick((440, 888), .3)								# Go to enemy's village
					sendFarmTroops(troops)									# Send troops
					print "Send troops, again!"
			else:
				print "Do nothing"

	pressKeys('{Esc}')


## 228 / 254 = (195, 182, 54)
#	exclamations
##	580, 370/409/448/487 (+39) = (182, 208, 47)
##	580, 578 (+39)


def checkRelatories():
	pointClick(Cords.r_RelatoryBtn, .5)	# Go to rels
	pointClick(Cords.r_OtherRels)		# Go to other rels
	pointClick(Cords.r_BattleRels, .5)	# Go to battle rels
	wait(5)

	if waitToLoad((400, 700),Colors.g_NotLoaded, False) == False:	# WaitToLoad Relatory Menu
		return

	checkIfNotRead(14,(580, 421))
	pressKeys('{Esc}')

def checkIfNotRead(rangee=0,initPos=(0,0)):
	img = screenGrab()
	for i in range(rangee):												# for each exclamation mark
		relatoryCord = (initPos[0], initPos[1]+(i*39))					# Current relatory coord
		if img.getpixel((725, 1100)) != (68, 54, 41):					# If new Rel
			i = -1
			continue
		if img.getpixel(relatoryCord) == (182, 208, 47):				# Tests if exclamation
			troops = checkTroops()
			print troops
			if troops == '':											# Check if enough troops
				break
			pointClick(Cords.r_RelatoryBtn, .5)							# Go to rels
			if waitToLoad(relatoryCord,(182, 208, 47), True) == False:	# WaitToLoad Relatory Menu
				return
			pointClick(relatoryCord)									# Go to exclamation
			if waitToLoad((400, 700),Colors.g_NotLoaded, False) == False:	# WaitToLoad battle relatory
				return
			sendFarmTroops(troops)										# Send troops
			print "Send troops to relatory "+ str(i) + ", again!"
		else:
			print "Do nothing to relatory "+ str(i)

		pressKeys('{Esc}')

def AttackPresetVillages(village):
	RstScrn()
	troopsToSend = checkTroops()
	pressKeys('{Esc}{Esc}{Esc}')
	hits = 0
	if troopsToSend == '':
		return
	f_barbVillages = io.open('Villages\\'+village+'\\Barbarians.txt', "r")
	barbVillages = f_barbVillages.readlines()
	f_barbVillages.close()

	f_attacks = io.open('Villages\\'+village+'\\Attacks.txt', "r")
	attacks = f_attacks.readlines()
	f_attacks.close()

	print 'Files loaded'

	for strcord in barbVillages:
		m_strcord = strcord.replace('\n','')
		print m_strcord
		for attackStats in attacks:
			print attackStats
			stats = attackStats.split('>')
			print stats
			stats[0] = stats[0].replace(' ', '')
			print str(stats[0] == m_strcord) + ' ' + stats[0]+'='+m_strcord
			if stats[0] == m_strcord:
				hits += 1
				returnStamp = stats[1].split(':')
				print time.time()-float(returnStamp[1])
				if time.time() > float(returnStamp[1]):
					troopsToSend = checkTroops()
					if troopsToSend == '':
						return
					removeline('Villages\\'+village+'\\Attacks.txt', attackStats)
					coords = stats[0].split('|')
					coords[0] = int(coords[0])
					coords[1] = int(coords[1])
					logAndAttack(village, coords, troopsToSend)
					break
		if hits == 0:
			troopsToSend = checkTroops()
			pressKeys('{Esc}{Esc}{Esc}')
			if troopsToSend == '':
				return
			coords = m_strcord.split('|')
			coords[0] = int(coords[0])
			coords[1] = int(coords[1])
			logAndAttack(village, coords, troopsToSend)
		else:
			hits = 0

def logAndAttack(village, coords, troopsToSend):
	attackVillage(coords, troopsToSend)
	vilCoord = village.split(' ')[0]
	vilCoord = vilCoord.split('-')
	vilCoord[0] = int(vilCoord[0])
	vilCoord[1] = int(vilCoord[1])
	print vilCoord
	dist = CalculateDist(vilCoord, coords)
	returnStamp = distToTimeCalc(dist, troopsToSend, village, True)
	coordinates = str(coords[0]) + '|' +str(coords[1])
	statsLine = coordinates + '>Returning:' + str(time.time()+returnStamp*2) + '\n'
	print statsLine
	with io.open('Villages\\'+village+'\\Attacks.txt', "a") as f_attacks:
		f_attacks.write(statsLine)


def attackVillage(villageCoords=(0,0), troopsToSend=''):
	if troopsToSend != '':
		searchCoords(villageCoords[0], villageCoords[1])
		pointClick((85,1120))
		wait(3)
		pressKeys(str(troopTypes[troopsToSend]))
		print 'Sending ' + troopsToSend + 's'


def sendFarmTroops(troops):
	wait(3)					# Waits
	pressKeys(str(troopTypes[troops]))
	print 'Sending ' + troops + 's'
	pressKeys("{Esc}")		# get back to Rels
	time.sleep(3)

def checkTroops():
	restMouse()
	pressKeys('r')
	wait(5)
	if waitToLoad((400, 700),Colors.g_NotLoaded, False) == False:	# WaitToLoad EnPoint Menu
		return

	img = screenGrab()

	if img.getpixel((7, 214)) != (82, 72, 63):
		wait(5)

	with io.open('Troops Velocities.txt', 'r') as f:
		for line in f:
			lineSplit = line.split('>')
			troopType = lineSplit[0]
			troop = getTroopType(troopTypes[troopType]-1, troopType)
			if troop != '':
				return troop
	pressKeys('{Esc}{Esc}')
	return ''

def getTroopType(row=0, troopType=''):
	img = screenGrab()
	# If more than 0 troops or more than half
	if grab((65, 326+(102*row), 72, 335+(102*row))) != 5045 or img.getpixel((380, 335+(102*row))) != (52, 61, 21):
		return troopType
	else:
		print 'No troops of this type'
		return ''

##-------------------------------##

def distToTimeCalc(dist=0, slowestTroop='', village='', barbarian=False):
	troopLine = ''
	EnPointLine = ''
	VelocityIncrease = 0		# must be 0 
	with io.open('Troops Velocities.txt', 'r') as f:
		for line in f:
			if slowestTroop in line:
				print line
				troopLine = line

	if troopLine != '':
		troopLine.replace('	','')
		args = troopLine.split('>')
		args[1] = to_seconds(args[1])
		print args
		timeDist = dist*args[1]
		print timeDist
		if barbarian == True:
			with io.open('Tribe.txt', 'r') as f:
				for line in f:
					if 'Raiding Path' in line:
						print line
						raidPathLine = line
			with io.open('Villages\\'+village+'\\Building Levels.txt', 'r') as f:
				for line in f:
					if 'EncounterPoint' in line:
						print line
						EnPointLine = line
			if EnPointLine != '':
				raidPathlvl = int(raidPathLine.split(':')[1])
				splited = EnPointLine.split(':')
				VelocityIncrease += int(splited[1])*50
				print VelocityIncrease
				newTime = (timeDist/(1 + (VelocityIncrease/float(100))))/float(1+(raidPathlvl/float(10)))
				print newTime
				return newTime
		else:
			return timeDist

def Hellow(texto='Olá'):
	pointClick((988, 57))
	pressKeys(texto)

def to_seconds(s):
	hr, min, sec = [float(x) for x in s.split(':')]
	return hr*3600 + min*60 + sec

def RstScrn():
	pointClick((85,1120))
	pressKeys('{Esc}{Esc}{Esc}   ')

def wait(daTime=0):
	time.sleep(daTime)


def gatherResources():
	searchCoords(614, 593)			# Search for coords
	if waitToLoad((7, 214), (82, 72, 63), False) == False:
		return
	time.sleep(3)					# Wait (map) to load
	leftClick()						# Click on 
	time.sleep(3)					# Wait selection to dismiss 
	leftClick()						# Click
	mousePos(Cords.g_GatherBtn)		# Go to "gather" button
	time.sleep(5)					# Wait to load
	leftClick()						# Click
	time.sleep(3)					# Wait
	mousePos(Cords.g_newGather)		# Go to make another gather
	leftClick()						# Click
	pressKeys('{Esc}')				# Dismiss menu

## ~384 ~553

## 570 1117
## 570 465
## 165 765

def upgrades(village):
	file = io.open('Villages\\'+ village +'\\To Build.txt', "r")
	buildList = file.readlines()
	file.close()

	img = screenGrab()
	if img.getpixel((1,111)) == (0,0,0):
		print 'Page not loaded!'
		RefreshPage()
	pix = (0,0)
	color = (0,0,0)
	for i in range(1,3):
		if i == 1:
			if img.getpixel((1887, 315)) != (249, 226, 113):
				print 'Space 1 filled '
				continue
			else:
				print 'Space 1 vague'
				pix = (1887, 315)
				color = (249, 226, 113)
		if i == 2:
			if img.getpixel((1887, 368)) != (249, 221, 95):
				print 'Space 2 filled'
				return
			else:
				print 'Space 2 vague'
				pix = (1887, 368)
				color = (249, 221, 95)
	print pix
	return

	for build in buildList:
		m_build = build.replace('\n', '')
		print m_build
		if m_build != '':
			img = screenGrab()
			if img.getpixel(pix) == color:
				upgraded = upgradeBuilding(m_build)
				if upgraded == True:
					print upgraded
					wait(3)
					img = screenGrab()
					if img.getpixel(pix) != color:
						removeline('Villages\\'+village+'\\To Build.txt', build)
						RefreshPage()
				else:
					removeline('Villages\\'+village+'\\To Build.txt', build)
		break

# 1887, 315

def upgradeBuilding(building=''):
	RstScrn()
	m_building = building.upper()
	print m_building
	pressKeys('hhh')		# Go to Building menu
	time.sleep(5)
	if m_building == 'MAIN BUILDING':
		pointClick(Cords.h_MainB)
		pressKeys('{Esc}')
		return True
	if m_building == 'TIMBER' :
		pointClick(Cords.h_Timber)
		pressKeys('{Esc}')
		return True
	if m_building == 'CLAY' :
		pointClick(Cords.h_Clay)
		pressKeys('{Esc}')
		return True
	if m_building == 'IRON' :
		pointClick(Cords.h_Iron)
		pressKeys('{Esc}')
		return True
	if m_building == 'FARM' :
		pointClick(Cords.h_Farm)
		pressKeys('{Esc}')
		return True
	if m_building == 'STORAGE' :
		pointClick(Cords.h_Storage)
		pressKeys('{Esc}')
		return True
	if m_building == 'CHAPEL' :
		pointClick(Cords.h_Chapel)
		pressKeys('{Esc}')
		return True
	if m_building == 'ENCOUNTER POINT' :
		pointClick(Cords.h_EnPoint)
		pressKeys('{Esc}')
		return True
	if m_building == 'BARRACKS' :
		pointClick(Cords.h_Barracks)
		pressKeys('{Esc}')
		return True
	if m_building == 'STATUE' :
		pointClick(Cords.h_Statue)
		pressKeys('{Esc}')
		return True
	if m_building == 'HOSPITAL' :
		pointClick(Cords.h_Hospital)
		pressKeys('{Esc}')
		return True
	if m_building == 'WALL' :
		pointClick(Cords.h_Wall)
		pressKeys('{Esc}')
		return True
	pointClick(Cords.h_Scroll)
	time.sleep(3)
	if m_building == 'MARKET' :
		pointClick(Cords.h_Market)
		pressKeys('{Esc}')
		return True
	if m_building == 'TAVERN' :
		pointClick(Cords.h_Tavern)
		pressKeys('{Esc}')
		return True
	if m_building == 'ACADEMY' :
		pointClick(Cords.h_Academy)
		pressKeys('{Esc}')
		return True
	if m_building == 'HALL OF ORDER' :
		pointClick(Cords.h_HofOrder)
		pressKeys('{Esc}')
		return True
	time.sleep(1)
	pressKeys('{Esc}')
	return False
		
def RefreshPage():
	leftClick()
	pressKeys('{F5}{F5}')
	wait(1)
	pressKeys('{F5}{F5}')
	wait(5)
	if waitToLoad((1,111), (0,0,0), False) == False:
		RefreshPage()
	else:
		return
	

def failsafes():
	if waitToLoad((1913, 120), (0,0,0), True) == False:
		RefreshPage()
		RstScrn()
	else:
		return

def searchCoords(x=0, y=0):
	RstScrn()
	pointClick(Cords.c_GobalIcon, .3)		# Go to global icon
	if waitToLoad((479, 961), (135, 98, 66)) == False:	# Wait to Load
		return
	wait(1)
	pointClick(Cords.c_xCordPos, .3)		# Go to x coords
	pressKeys('^a'+str(x))					# Select all and type coord
	time.sleep(1)							# Wait
	pointClick(Cords.c_yCordPos, .3)		# Go to y coords
	pressKeys('^a'+str(y))					# Select all and type coord
	mousePos(Cords.c_GoBtn)					# Go to "go" button
	leftClick(.3)							# Click
	pointClick(Cords.c_GobalIcon, .3)		# Go to Global icon
	mousePos(Cords.c_ScreenCenter)			# Go to center of the screen


def restMouse():
	mousePos((0, 0))

def replaceline(file_path, pattern, subst):
	hit = False
	#Create temp file
	fh, abs_path = mkstemp()
	with open(abs_path,'w') as new_file:
		with open(file_path) as old_file:
			for line in old_file:
				if pattern in line and hit == False:
					hit = True
					new_file.write(line.replace(pattern, subst))
				else:
					new_file.write(line)

	close(fh)
	#Remove original file
	remove(file_path)
	#Move new file
	move(abs_path, file_path)

def removeline(file_path, lineToRemove):
	f = open(file_path,"r+")
	d = f.readlines()
	f.seek(0)
	hit = False
	for i in d:
		if i != lineToRemove:
			f.write(i)
		else:
			if hit == False:
				hit = True
			else:
				f.write(i)
	f.truncate()
	f.close()


troopTypes = 	{'Spearman':1,
				'Swordsman':2,
				'Viking':3,
				'Archer':4,
				'Light Cv':5,
				'Mnt Archer':6,
				'Heavy Cv':7,
				'Berseker':8}


def waitToLoad(cord=(0,0), pixel=(0,0,0), Equal=True, lim=(10)):
	lim*2
	for i in range(lim):
		img = screenGrab()
		if (img.getpixel(cord) == pixel) == Equal:
			print 'Loaded!'
			return True
			break
		else:
			time.sleep(.5)

	print 'Did not load'
	return False


def CalculateDist(origin=(0,0),dest=(0,0)):
	z1 = origin[0] + 0.5 if isodd(origin[1]) else origin[0] - 0.5
	z2 = dest[0] + 0.5 if isodd(dest[1]) else dest[0] - 0.5
	d1 = sqrt((z1 - z2)**2 + 0.75 * (origin[1] - dest[1])**2)
	d2 = sqrt((origin[0] - dest[0])**2 + 0.75 * (origin[1] - dest[1])**2)
	d = (d1 + d2) / 2
#	print str(d)
	return d


def isodd(number=0):
	if number%2==0:
		return False
	else:
		return True

def nextVillage():
	RstScrn()
	pressKeys('+{Right}')


##--------------------------------##
## BOT Tick

schedule = {'Upgrades':240,
			'Relatories':120,
			'Resources':60,
			'Buildings':30}


def botTick():
	print 'Mouse is resting, starting schedule check'
	for p, v in schedule.items():
	#	if time.time() > v:
		if p == 'Upgrades':
			print 'Check upgrades'
		#	upgrades()
			v = time.time() + 230

		if p == 'Relatories':
			print 'Check relatories'
		#	checkRelatories()
			v = time.time() + 100

		if p == 'Resources':
			print 'Check resources'
		#	gatherResources()
			v = time.time() + 40

		if p == 'Buildings':
			print 'Check buildings'
		#	checkBuildings()
			v = time.time() + 30

	for village in next(walk('Villages'))[1]:
	#	checkRelatories()
		failsafes()
		AttackPresetVillages(village)
		gatherResources()
		checkBuildings()
		upgrades(village)
		nextVillage()

	restMouse()
	wait(10)
	botTick()

def startGame():
	logIn()
	time.sleep(60)
	botTick()

def main():
	pass


def what():
	pointClick((744, 1128), .5)
	pressKeys('É oq quero pra minha vida{Enter}=P{Enter}')


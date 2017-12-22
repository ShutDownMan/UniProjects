# -*- coding: utf-8 -*-
from __future__ import unicode_literals
import io
import time
import fileinput
import win32api, win32con
import win32com.client
import collections
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
	c_ScreenCenter = (960, 610)

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
	mousePos((1840, 315))
	leftClick(.5)

## 1840 315/ 370 = (187, 214, 86)

def CalcTotalCarryCapacity(village, troops=(0,0,0,0,0,0,0,0)):
	totalCC = collections.OrderedDict({'Unit': 0})
	totalSumCC = 0

	with io.open('Troops Carrying Capacity.txt', 'r') as f:
		i = 0
		for line in f:
			m_stat = line.replace('\t','')
			m_stat = m_stat.strip()
			splited = m_stat.split('>')
			totalSumCC += int(splited[1])*troops[i]
			totalCC.update({str(splited[0]):int(splited[1])})
			i += 1
		print 'Total carry capacity: ' + str(totalSumCC)+'\n----------'
	#	print totalCC

	CCRationed = totalSumCC/float(50)
	print 'Ideal division per farm troop:\n' + str(CCRationed)+'\n----------'

	for k, v in totalCC.iteritems():
		if v > 0:
			quant = round(CCRationed/v)
			print k+'s Farm:\n'	+ str(quant)+'\n----------'


def addBuildingToLst(village, building):
	with io.open('Villages\\'+village+'\\To Build.txt', "a") as f_builds:
		f_builds.write(unicode(building.upper()+'\n'))
		print building + " was added to list!"

def LstBuild(village):
	with io.open('Villages\\'+village+'\\To Build.txt', "r") as f_builds:
		print 'Listing buildings:'
		for line in f_builds.readlines():
			print line.strip()
		print '------------'

def removeAttackLog(village, coord):
	f = open('Villages\\'+village+'\\Attacks.txt', "r+")
	d = f.readlines()
	f.seek(0)
	hit = False
	for i in d:
		if coord in i:
			hit = True
			print 'Removing attack log '+coord+' from village: '+village
		else:
			f.write(i)

	if hit == False:
		print "No log found"

	f.truncate()
	f.close()
	
def addBarbToVillage(village, barbVillage, coop=''):
	if coop == '':
		f = open('Villages\\'+village+'\\Barbarians.txt', "r+")
	else:
		f = open('Coops\\'+coop+'\\Villages\\'+village+'\\Barbarians.txt', "r+")

	d = f.readlines()
	f.seek(0)
	hit = False

	for i in d:
		if barbVillage in i:
			if hit == True:
				print "Duplicated coord: " + i
				continue
			else:
				hit = True
				print "Village already added!\n"
				f.write(i)
				continue
		f.write(i)

	if hit == False:
		print "Village successfully added"
		f.write(barbVillage+'\n')

	f.truncate()
	f.close()
	sortBarbs(village, coop)

def addBarb(barb):
	with io.open('Gobal barbarian list.txt', "a") as file:
		file.write(barb+'\n')
	sortBarbs()
	UpdateBarbLst()


def sortBarbs(village='', coop='', lim=60):
	if village == '':
		f_barbVillages = io.open('Gobal barbarian list.txt', "r")
	else:
		if coop == '':
			f_barbVillages = io.open('Villages\\'+village+'\\Barbarians.txt', "r")
		else:
			f_barbVillages = io.open('Coops\\'+coop+'\\Villages\\'+village+'\\Barbarians.txt', "r")

	barbVillages = f_barbVillages.readlines()
	f_barbVillages.close()

	if village != '':
		vilSplit = village.split(' ')
		vilCoord = vilSplit[len(vilSplit)-1]
		vilCoord = vilCoord.split('-')
		vilCoord[0] = int(vilCoord[0])
		vilCoord[1] = int(vilCoord[1])
	else:
		vilCoord = [500, 500]

	arr = {}
	a = 0

	for line in barbVillages:
		if line != '':
			a +=1
			hit = False
			splited = line.split('|')
			cord = (int(splited[0]), int(splited[1]))
			dist = CalculateDist(vilCoord, cord)
			for k,v in arr.items():
				if k == cord:
					hit = True
			if hit == False:
				arr.update({cord:dist})

	sortedList = collections.OrderedDict(sorted(arr.iteritems(), key=lambda (k,v): (v,k)))

	if village == '':
		f = io.open('Gobal barbarian list.txt', "r+")
	else:
		if coop == '':
			f = io.open('Villages\\'+village+'\\Barbarians.txt', "r+")
		else:
			f = io.open('Coops\\'+coop+'\\Villages\\'+village+'\\Barbarians.txt', "r+")
	f.seek(0)
	a = 0
	for i in sortedList:
		a += 1
		f.write((str(i[0]) +'|'+ str(i[1])) + '\n')
		if a == lim and village != '':
			break

	f.truncate()
	f.close()
	print "The village " + village + "'s barb list have been updated!"


def UpdateBarbLst():
	globalList = ''
	with io.open('Gobal barbarian list.txt', "r") as file:
		globalList = file.readlines()

	for village in next(walk('Villages'))[1]:
		with io.open('Villages\\'+village+'\\Barbarians.txt', "r+") as f:
			for line in globalList:
				f.write(line)
			f.truncate()
		sortBarbs(village)


def CalcAverageBarbDist(village):
	f = open('Villages\\'+village+'\\Barbarians.txt', "r")
	d = f.readlines()
	f.seek(0)

	totalSum = 0
	average = 0


	vilSplit = village.split(' ')
	vilCoord = vilSplit[len(vilSplit)-1]
	vilCoord = vilCoord.split('-')
	vilCoord[0] = int(vilCoord[0])
	vilCoord[1] = int(vilCoord[1])

	for line in d:
		splited = line.split('|')
		cord = (int(splited[0]), int(splited[1]))
		dist = CalculateDist(vilCoord, cord)
		totalSum += dist


	print 'Total sum of distances:\n' + str(totalSum) + '\n-------------'

	average = totalSum/len(d)

	print 'Average distances:\n' + str(average) + '\n-------------'

	f.close()

	return average


def CalcAverageTimeAttack(viilage, troops=(0,0,0,0,0,0,0,0)):

	tUnits = {}
	sumOfTroops = 0
	totalSum = 0
	averageDist = 0
	i = 0

	with io.open('Troops Velocities.txt', 'r') as f:
		for line in f:
			args = line.replace('\t','')
			args = line.split('>')
			args[1] = to_seconds(args[1])
			print args[1]*troops[i]
			totalSum += int(args[1])*troops[i]
			tUnits.update({str(args[0]):int(args[1])})
			sumOfTroops += troops[i]
			i += 1

	averageDist = CalcAverageBarbDist(village)

	print 'Sum of troops: ' + str(sumOfTroops) + '\n----------'

	print 'Total time spam: ' + str(totalSum) + '\n----------'

	print 'Average time spam: ' + str((totalSum/float(sumOfTroops))*averageDist)+'\n----------'




##----------------------------------##
## Donation stuff

def DonateOverflow(village):
	f_configs = io.open('Villages\\'+village+'\\configs.txt', "r")
	configs = f_configs.readlines()
	f_configs.close()

	donateAmount = ''
	w_boost = ''
	c_boost = ''
	i_boost = ''


	for line in configs:
		splited = (line.strip()).split(':')
		if 'Donate Amount' in line:
			donateAmount = splited[1]
			print donateAmount
			continue

		if 'Wood Boost' in line:
			w_boost = splited[1]
			print w_boost
			continue

		if 'Clay Boost' in line:
			c_boost = splited[1]
			print c_boost
			continue

		if 'Iron Boost' in line:
			i_boost = splited[1]
			print i_boost
			continue

	for i in range(3):
		wait(2)
		bar = grab((1469+(i*94), 137, 1470+(i*94), 145))
		if i == 0:
			if w_boost == 'True':
				if bar != 390:
					print 'Donating Wood'
					donateToTribe('Wood', donateAmount)
					continue
				else:
					if bar == 231:
						replaceline('Villages\\'+village+'\\configs.txt', line, splited[0]+':'+'False')
			else:
				if bar != 231:
					print 'Donating Wood'
					donateToTribe('Wood', donateAmount)
					continue
				else:
					if bar == 390:
						replaceline('Villages\\'+village+'\\configs.txt', line, splited[0]+':'+'True')


		if i == 1:
			if c_boost == 'True':
				if bar != 390:
					print 'Donating Clay'
					donateToTribe('Clay', donateAmount)
					continue
				else:
					if bar == 231:
						replaceline('Villages\\'+village+'\\configs.txt', line, splited[0]+':'+'False')
			else:
				if bar != 231:
					print 'Donating Clay'
					donateToTribe('Clay', donateAmount)
					continue
				else:
					if bar == 390:
						replaceline('Villages\\'+village+'\\configs.txt', line, splited[0]+':'+'True')

		if i == 2:
			if i_boost == 'True':
				if bar != 390:
					print 'Donating Iron'
					donateToTribe('Iron', donateAmount)
					continue
				else:
					if bar == 231:
						replaceline('Villages\\'+village+'\\configs.txt', line, splited[0]+':'+'False')
			else:
				if bar != 231:
					print 'Donating Iron'
					donateToTribe('Iron', donateAmount)
					continue
				else:
					if bar == 390:
						replaceline('Villages\\'+village+'\\configs.txt', line, splited[0]+':'+'True')


def donateToTribe(resource, donateAmount):

	RstScrn()
	wait(1)
	pressKeys('p')
	pressKeys('p')
	if waitToLoad((695, 428), (44, 33, 27), True) == False:
		return
	wait(1)
	if resource == 'Wood':
		pointClick((1150, 620))
		pressKeys(donateAmount)
		pointClick((1045, 825))
		pressKeys('{Esc}{Esc}{Esc}')
		wait(3)


	if resource == 'Clay':
		pointClick((1150, 670))
		pressKeys(donateAmount)
		pointClick((1045, 825))
		pressKeys('{Esc}{Esc}{Esc}')
		wait(3)

	if resource == 'Iron':
		pointClick((1150, 720))
		pressKeys(donateAmount)
		pointClick((1045, 825))
		pressKeys('{Esc}{Esc}{Esc}')
		wait(3)

	print 'Donated '+donateAmount+' of '+resource

#1150 620, 670 (50)
#1045 825


##----------------------------------##



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

	f_attacks = io.open('Gobal Attacks List.txt', "r")
	attacks = f_attacks.readlines()
	f_attacks.close()

	print 'Files loaded'

	# hited = 0
	# for attackStats in attacks:
	# 	for strcord in barbVillages:
	# 		m_strcord = strcord.replace('\n','')
	# 		stats = attackStats.split('>')
	# 		stats[1] = stats[1].replace(' ', '')
	# 		if stats[1] == m_strcord:
	# 			hited += 1
	# 	print hited
	# 	if hited == 0:
	# 		removeline('Villages\\'+village+'\\Attacks.txt', attackStats)
	# 	hited = 0
	# return


	attacksLen = 0
	for attackStats in attacks:
	#	print attackStats
		stats = attackStats.split('>')
	#	print stats
		stats[1] = stats[1].replace(' ', '')
	#	print str(stats[1] == m_strcord) + ' ' + stats[1]+'='+m_strcord
		returnStamp = stats[2].split(':')
		vilCord = getVillageCoord(village)
		if time.time() < float(returnStamp[1]) and stats[0] == vilCord:
			attacksLen += 1

	print 'Attacks in course: ' + str(attacksLen)
	if attacksLen >= 50:
		return

	for strcord in barbVillages:
		attacksLen = 0
		m_strcord = strcord.strip()
	#	print m_strcord
		for attackStats in attacks:
		#	print attackStats
			stats = attackStats.split('>')
		#	print stats
			stats[1] = stats[1].replace('\t', '')
		#	print str(stats[1] == m_strcord) + ' ' + stats[1]+'='+m_strcord
			returnStamp = stats[2].split(':')
			if stats[1] == m_strcord:
				print 'Faltam '+str(time.time()-float(returnStamp[1]))
				hits += 1
				print 'Truuuuuuue'
				if time.time() > float(returnStamp[1]):
					troopsToSend = checkTroops()
					if troopsToSend == '':
						return
					removeline('Gobal Attacks List.txt', attackStats)
					coords = stats[1].split('|')
					coords[0] = int(coords[0])
					coords[1] = int(coords[1])
					failsafes()
					logAndAttack(village, coords, troopsToSend)
					attacksLen = 0
					break
			vilCord = getVillageCoord(village)
	#		print str(stats[0]) + '====' + str(vilCord)
			if time.time() < float(returnStamp[1]) and stats[0] == vilCord:
				attacksLen += 1

		print 'Attacks in course: ' + str(attacksLen)
		if attacksLen >= 50:
			return

		if hits == 0:
			troopsToSend = checkTroops()
			pressKeys('{Esc}{Esc}{Esc}')
			if troopsToSend == '':
				return
			coords = m_strcord.split('|')
			coords[0] = int(coords[0])
			coords[1] = int(coords[1])
			failsafes()
			logAndAttack(village, coords, troopsToSend)
		else:
			hits = 0

def logAndAttack(village, coords, troopsToSend):
	attackVillage(coords, troopsToSend)

	vilSplit = village.split(' ')
	vilCoord = vilSplit[len(vilSplit)-1]
	vilCoord = vilCoord.split('-')
	vilCoord[0] = int(vilCoord[0])
	vilCoord[1] = int(vilCoord[1])

#	print vilCoord
	dist = CalculateDist(vilCoord, coords)
	returnStamp = distToTimeCalc(dist, troopsToSend, village, True)
	barbCord = str(coords[0]) + '|' +str(coords[1])
	vilCord = str(vilCoord[0]) + '|' +str(vilCoord[1])
	statsLine = vilCord + '>'+ barbCord + '>Returning:' + str(time.time()+returnStamp*2) + '\n'
#	print statsLine
	with io.open('Villages\\'+village+'\\Attacks.txt', "a") as f_attacks:
		f_attacks.write(statsLine)
	with io.open('Gobal Attacks List.txt', "a") as f_attacks:
		f_attacks.write(statsLine)

def getVillageCoord(village):
	vilSplit = village.split(' ')
	vilCoord = vilSplit[len(vilSplit)-1]
	vilCoord = vilCoord.split('-')
	vilCoord[0] = int(vilCoord[0])
	vilCoord[1] = int(vilCoord[1])
	vilCord = str(vilCoord[0]) + '|' +str(vilCoord[1])

	return vilCord


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
	pressKeys("{Esc}")
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
	return ''

def getTroopType(row=0, troopType=''):
	img = screenGrab()
	# If more than 0 troops or more than half
	if grab((65, 326+(102*row), 72, 335+(102*row))) != 5045 or img.getpixel((380, 335+(102*row))) != (52, 61, 21):
		return troopType
	else:
		print 'No troops of this type'
		return ''

def updateGlobalAttacksLst():
	f_attacks = io.open('Gobal Attacks List.txt', "r")
	attacks = f_attacks.readlines()
	f_attacks.close()

	print 'Files loaded'

	for attackStats in attacks:
		stats = attackStats.split('>')
	#	print stats
		stats[1] = stats[1].replace('\t', '')
	#	print str(stats[1] == m_strcord) + ' ' + stats[1]+'='+m_strcord
		returnStamp = stats[2].split(':')
		if time.time() > float(returnStamp[1]):
			removeline('Gobal Attacks List.txt', attackStats)


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


def to_seconds(s):
	hr, minute, sec = [float(x) for x in s.split(':')]
	return hr*3600 + minute*60 + sec

def RstScrn():
	pointClick((85,1120))
	pressKeys('{Esc}{Esc}{Esc}   ')

def wait(daTime=0):
	time.sleep(daTime)


def gatherResources():
	RstScrn()
	searchCoords(479, 491)			# Search for coords
	if waitToLoad((7, 214), (82, 72, 63), False) == False:
		return
	time.sleep(3)					# Wait (map) to load
	leftClick()						# Click on 
	time.sleep(.5)					# Wait selection to dismiss 
	leftClick()						# Click
	mousePos(Cords.g_GatherBtn)		# Go to "gather" button
	time.sleep(4)					# Wait to load
	leftClick()						# Click
	time.sleep(.5)					# Wait
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
	spaceOneFilled = True
	for i in range(1,3):
		if i == 1:
			if img.getpixel((1887, 315)) != (249, 226, 113):
				print 'Space 1 filled '
				continue
			else:
				print 'Space 1 vague'
				spaceOneFilled = False
				pix = (1887, 315)
				color = (249, 226, 113)
		if i == 2:
			if img.getpixel((1887, 368)) != (249, 226, 113):
				print 'Space 2 filled'
				return
			else:
				print 'Space 2 vague'
				pix = (1887, 368)
				color = (249, 226, 113)

		for build in buildList:
			m_build = build.strip()
			print m_build
			if m_build != '':
				img = screenGrab()
				if img.getpixel(pix) == color:
					upgraded = upgradeBuilding(m_build, not spaceOneFilled)
					if upgraded == True:
						print upgraded
						wait(5)
						img = screenGrab()
						if img.getpixel(pix) != color:
							removeline('Villages\\'+village+'\\To Build.txt', build)
							if spaceOneFilled == False:
								spaceOneFilled = True
								continue
							RefreshPage()
						else:
							print 'Did not upgrade, check reasons'
					else:
						removeline('Villages\\'+village+'\\To Build.txt', build)
			break

# 1887, 315

def upgradeBuilding(building='', filled=False):
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
	if m_building == 'RALLY POINT' :
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
		if filled == False:
			pointClick(Cords.h_Market)
		else:
			pointClick((Cords.h_Market[0], Cords.h_Market[1]+100))

		pressKeys('{Esc}')
		return True
	if m_building == 'TAVERN' :
		if filled == False:
			pointClick(Cords.h_Tavern)
		else:
			pointClick((Cords.h_Tavern[0], Cords.h_Tavern[1]+100))
		pressKeys('{Esc}')
		return True
	if m_building == 'ACADEMY' :
		if filled == False:
			pointClick(Cords.h_Academy)
		else:
			pointClick((Cords.h_Academy[0], Cords.h_Academy[1]+100))
		pressKeys('{Esc}')
		return True
	if m_building == 'HALL OF ORDER' :
		if filled == False:
			pointClick(Cords.h_HofOrder)
		else:
			pointClick((Cords.h_HofOrder[0], Cords.h_HofOrder[1]+100))
		pressKeys('{Esc}')
		return True
	time.sleep(1)
	pressKeys('{Esc}')
	return False
		
def RefreshPage():
	pointClick((120, 55))
	pressKeys('{F5}{F5}')
	wait(1)
	pressKeys('{F5}{F5}')
	wait(5)
	if waitToLoad((1,111), (0,0,0), False, 13) == False:
		RefreshPage()
	else:
		return
	

def failsafes():
	if waitToLoad((1912, 118), (38,17,16), True) == False:
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

	if hit == True:
		print 'Pattern Found!'

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
	RstScrn()


##--------------------------------##
## BOT Tick

schedule = {'Upgrades':240,
			'Relatories':120,
			'Resources':60,
			'Buildings':30}

def StartBot():
	global screenshtStamp 
	screenshtStamp = 0 
	with io.open('configs.txt', 'r') as f:
		for line in f.readlines():
			if 'screenshtStamp' in line:
				screenshtStamp = int(line.split(':')[1])
				print screenshtStamp

	botTick()

def botTick():
	# for p, v in schedule.items():
	# #	if time.time() > v:
	# 	if p == 'Upgrades':
	# 		print 'Check upgrades'
	# 	#	upgrades()
	# 		v = time.time() + 230

	# 	if p == 'Relatories':
	# 		print 'Check relatories'
	# 	#	checkRelatories()
	# 		v = time.time() + 100

	# 	if p == 'Resources':
	# 		print 'Check resources'
	# 	#	gatherResources()
	# 		v = time.time() + 40

	# 	if p == 'Buildings':
	# 		print 'Check buildings'
	# 	#	checkBuildings()
	# 		v = time.time() + 30

	global screenshtStamp

	if time.time() > screenshtStamp:
		print screenshtStamp
		img = screenGrab()
		print 'Snap!'
		img.save('Snaps\\Snap__' + str(int(time.time())) + '.png', 'PNG')
		replaceline('configs.txt', str(screenshtStamp), str(int(time.time())+int(1600)))
		screenshtStamp += int(1600)


	for village in next(walk('Villages'))[1]:
	#	checkRelatories()
		failsafes()
		AttackPresetVillages(village)
		checkBuildings()

		failsafes()
		gatherResources()

		failsafes()
		checkBuildings()

		failsafes()
		upgrades(village)
		checkBuildings()

		failsafes()
		DonateOverflow(village)
		checkBuildings()

		failsafes()
		nextVillage()

	# for coop in next(walk('Coops'))[1]:
	# 	for village in next(walk('Coops\\'+coop+'\\Villages'))[1]:
	# 		pointClick((1912, 118)) # Log out btn
	# 		wait(3)
	# 		pointClick((1825, 355))
	# 		wait(5)
			
	# 		failsafes()
	# 		AttackPresetVillages(village)
	# 		checkBuildings()

	# 		failsafes()
	# 		gatherResources()

	# 		failsafes()
	# 		checkBuildings()

	# 		failsafes()
	# 		upgrades(village)
	# 		checkBuildings()

	# 		failsafes()
	# 		DonateOverflow(village)
	# 		checkBuildings()

	# 		failsafes()
	# 		nextVillage()

	# 		pointClick((1912, 118)) # Log out btn
	# 		wait(3)
	# 		pointClick((1825, 315))
	# 		wait(5)

	# 		# 1825 355

	restMouse()
	wait(10)
	botTick()

def startGame():
	logIn()
	time.sleep(60)
	botTick()

def main():
	pass

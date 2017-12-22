# -*- coding: utf-8 -*-
from __future__ import unicode_literals

	# 000 000 = 397|397

	# 420 480 = 481|493

	# 450 480 = 487|493

	# 800 520 = 

	# 30 = 6
	# 5p por 1xy

from PIL import Image
import os

def GetBarbs():
	img = Image.open('..\\this.png')

	pix = (135, 135)
	xCord = 135
	yCord = 135


	for x in range(145):
		xCord += 5
		for y in range(145):
			yCord += 5
			if img.getpixel((xCord, yCord)) == (102, 102, 102):
				print 'Barbarian at ' + str((xCord, yCord))
				x_Coord = xCord/5+397
				y_Coord = yCord/5+397
				print 'in other words, at ' + str(x_Coord) + '|' + str(y_Coord) + '\n---------------------'
				addBarb(str(x_Coord) + '|' + str(y_Coord))
		yCord = 135
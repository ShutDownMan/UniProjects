# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from PIL import Image
import requests
from StringIO import StringIO


class GetAllBarbs():

	def __init__(self):
		self.get_barbs()

	def get_barbs(self):
		response = requests.get("http://br.tw2-tools.com/br16/img_map/hash/eb7cd536c9a5e56c8098ad6cb74ee5e7/")
		img = Image.open(StringIO(response.content))

		barb_list = []

	#	img = Image.open('\\World Map\\Barbarians World Map.png')

		xCord = 66
		yCord = 65

		for y in range(270):
			yCord += 3
			for x in range(270):
				xCord += 3
				if img.getpixel((xCord, yCord)) == (102, 102, 102):
					print 'Barbarian at ' + str((xCord, yCord))
					x_Coord = xCord/3+329
					y_Coord = yCord/3+330
					print 'in other words, at ' + str(x_Coord) + '|' + str(y_Coord) + '\n---------------------'

					barb_list.append((x_Coord, y_Coord))
			xCord = 66

		return barb_list

	# 000 000 = 397|397

	# 420 480 = 481|493

	# 450 480 = 487|493

	# 684 408 = 557|465

	# 481 411 = 556|466

	# 30 = 6
	# 5p por 1xy
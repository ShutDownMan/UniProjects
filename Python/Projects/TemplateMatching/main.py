#!/bin/python

# Python program to illustrate
# multiscaling in template matching
import cv2
import numpy as np
import imutils
import os
import math
import sys

threshold = 0.85
minDist = 5

def main():
	# Get arguments from command line
	img_rgb_path = sys.argv[1]
	template_path = sys.argv[2]

	# Get matches for image
	result = getMatches(img_rgb_path, template_path)

	# Print best matches 
	print ('Best Match = ' + str(result))

	# Draw bounding boxes on image
	image = drawBoundingBox(img_rgb_path, result)

	# Show image
	cv2.imshow('Image', image)
	cv2.waitKey(0)
	input()


# Returns list of matching bounding boxes given an image and a template
def getMatches(img_rgb_path, template_path):
	matchesScaledList = []
	bestMatch = None
	bestMatchLen = 0

	for scale in np.linspace(0.2, 1.0, 50)[::-1]:
		# Get matches from each scale
		currentMatch = getMatchesScaled(img_rgb_path, template_path, scale)
		# If there's at least one match
		if len(currentMatch) > 1:
			# If it is the best match yet
			if len(currentMatch) > bestMatchLen:
				bestMatch = currentMatch
				bestMatchLen = len(currentMatch)
			matchesScaledList.append(currentMatch)
			print(currentMatch)

	return bestMatch

def getMatchesScaled(img_rgb_path, template_path, scale):
	resultList = []

	# Read the main image
	img_rgb = cv2.imread(img_rgb_path)
	#img_rgb = cv2.imread('images/test_image.png')

	# Convert to grayscale
	img_gray = cv2.cvtColor(img_rgb, cv2.COLOR_BGR2GRAY)

	# Read the template
	template = cv2.imread(template_path, 0)

	# Store width and heigth of template in w and h
	tW, tH = template.shape[::-1]
	found = None
	result = None

	# resize the image according to the scale, and keep track
	# of the ratio of the resizing
	resized = imutils.resize(img_gray, width = int(img_gray.shape[1] * scale))
	r = img_gray.shape[1] / float(resized.shape[1])
	print('r = ' + str(r))

	# Tries to match resized image to template
	result = cv2.matchTemplate(resized, template, cv2.TM_CCOEFF_NORMED)

	#cv2.imshow('Image', result)
	#cv2.waitKey()

	print(cv2.minMaxLoc(result))
	#input()

	# if the resized image is smaller than the template, then return
	if resized.shape[0] < tH or resized.shape[1] < tW:
		return resultList

	loc = np.where(result >= threshold)

	startX = startY = oldX = oldY = float("inf")
	for pt in zip(*loc[::-1]):
		# Calculate the bounding box of the match found
		(startX, startY) = (int(pt[0] * r), int(pt[1] * r))
		(endX, endY) = (int((pt[0] + tW) * r), int((pt[1] + tH) * r))

		if math.hypot(startX - oldX, startY - oldY) > minDist:
			# store the bounding box where the match was found
			resultList.append((startX, startY, endX, endY))
			
			#cv2.rectangle(img_rgb, pt, (pt[0] + w, pt[1] + h), (0,0,255), 2) 
		
		(oldX, oldY) = (startX, startY)

	return resultList

def drawBoundingBox(img_rgb_path, boxes):
	# Read the main image
	img_rgb = cv2.imread(img_rgb_path)

	# For each box in boxes
	for box in boxes:
		# Draw bounding box on given image
		(startX, startY, endX, endY) = box
		cv2.rectangle(img_rgb, (startX, startY), (endX, endY), (0, 0, 255), 2)
	
	#print('(' + str(startX) + ',' + str(startY) + ')')
	#print('(' + str(endX) + ',' + str(endY) + ')')

	return img_rgb

if __name__ == '__main__':
	print(sys.argv[1] + ', ' + sys.argv[2])
	main()
	#main('images/test_image.png', 'images/pattern_medium.png')

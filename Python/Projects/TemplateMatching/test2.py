#!/bin/python

import cv2
import numpy as np
from matplotlib import pyplot as plt
 
img_rgb = cv2.imread('images/test_image.png')
img_gray = cv2.cvtColor(img_rgb, cv2.COLOR_BGR2GRAY)
template = cv2.imread('images/pattern_big.png',0)
w, h = template.shape[::-1]

res = cv2.matchTemplate(img_gray,template,cv2.TM_CCOEFF_NORMED)

cv2.imshow('Image', res)
cv2.waitKey(0)

threshold = 0.85
loc = np.where( res >= threshold)
for pt in zip(*loc[::-1]):
	print('WTF: ' + str(pt))
	print(cv2.minMaxLoc(res))
	cv2.rectangle(img_rgb, pt, (pt[0] + w, pt[1] + h), (0,0,255), 2) 

cv2.imshow('Image', img_rgb)
cv2.waitKey(0)
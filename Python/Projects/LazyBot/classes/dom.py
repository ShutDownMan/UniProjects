# -*- coding: utf-8 -*-
from __future__ import unicode_literals
import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.support import expected_conditions as EC


class DOM():

	Master = None

	def __init__(self, master):
		self.Master = master
		print "DOM module loaded!\n" + str(master)

	def FindElem(self, cssPath, lim=10):
		if self.WaitToLoadCSS(cssPath, lim) == True:
			elem = self.Master.foxDriver.find_element_by_css_selector(cssPath)
			return elem

	def FindElemByxPath(self, xpath, lim=10):
		if self.WaitToLoadxPath(xpath, lim) == True:
			elem = self.Master.foxDriver.find_element_by_xpath(xpath)
			return elem

	def FindElems(self, cssPath, lim=10):
		if self.WaitToLoadCSS(cssPath, lim) == True:
			elem = self.Master.foxDriver.find_elements_by_css_selector(cssPath)
			return elem

	def get_elem(self, cssPath):
		elem = None
		try:
			elem = self.Master.foxDriver.find_element_by_css_selector(cssPath)
		except:
			print "Elem not Found!"
			
		if elem != None:
			return elem

	def get_elems(self, cssPath):
		elem = None
		try:
			elem = self.Master.foxDriver.find_elements_by_css_selector(cssPath)
		except:
			print "Elems not Found!"
			
		if len(elem) > 0:
			return elem

	def get_elem_by_xpath(self, xPath):
		elem = None
		try:
			elem = self.Master.foxDriver.find_element_by_xpath(xPath)
		except:
			print "Elem not Found!"
			
		if elem != None:
			return elem


	def FindElemAttribute(self, element, attribute, value):
		try:
			attr = element.get_attribute(attribute);
			if (attr != None):
				if attr == value:
					return True;

		except:
			print "FindElemAttribute not worked!" 

	def AttributeValue(self, element, attribute):
		try:
			attr = element.get_attribute(attribute);
			if (attr != None):
				return attr;

		except:
			print "attributeValue not worked!" 


	def WaitToLoadCSS(self, cssPath, lim=10):
		try:
			WebDriverWait(self.Master.foxDriver, lim).until(EC.presence_of_element_located((By.CSS_SELECTOR, cssPath)))
			print "Page is ready!"
			return True
		except TimeoutException:
			print "Loading took too much time!"

	def WaitToLoadxPath(self, xpath, lim=10):
		try:
			WebDriverWait(self.Master.foxDriver, lim).until(EC.presence_of_element_located((By.XPATH, xpath)))
			print "Page is ready!"
			return True
		except TimeoutException:
			print "Loading took too much time!"

	def Type(self, element, text):
		for i in range(len(text)):
			element.send_keys(text[i])
			time.sleep(.01)

	def sendKeys(self, element, keys):
		element.send_keys(keys)
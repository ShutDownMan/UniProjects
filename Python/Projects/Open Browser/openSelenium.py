# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from selenium import webdriver
from selenium.webdriver.support import ui
from selenium.webdriver.common.keys import Keys

def page_is_loaded(driver):
    return driver.find_element_by_tag_name("body") != None

driver = webdriver.Edge()
driver.get("https://www.facebook.com/")

wait = ui.WebDriverWait(driver, 10)
wait.until(page_is_loaded)

usernameField = driver.find_element_by_id("username")
usernameField.send_keys("user@example.com")

password_field = driver.find_element_by_id("pass")
password_field.send_keys("password")
password_field.send_keys(Keys.RETURN)
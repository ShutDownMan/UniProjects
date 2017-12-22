# -*- coding: utf-8 -*-
from __future__ import unicode_literals
import win32ui
import time
name = "Tribal Wars 2 - O jogo online de estratégia medieval" #just an example of a window I had open at the time
w = win32ui.FindWindow( None, name )
t1 = time.time()
count = 0
while count < 1000:
	dc = w.GetWindowDC()
	dw = 
	#dc.GetPixel(1,1)
	#dc.save(os.getcwd() + '\\Snap__' + str(int(time.time())) + '.png', 'PNG')
	dc.SaveDC(os.getcwd() + '\\Snap__' + str(int(time.time())) + '.png', 'PNG')
	dc.DeleteDC()
	count +=1
t2 = time.time()
tf = t2-t1
it_per_sec = int(count/tf)
print (str(it_per_sec) + " iterations per second")
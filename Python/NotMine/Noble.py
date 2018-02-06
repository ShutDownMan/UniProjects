#!/usr/bin/env python
# -*- coding: utf-8 -*-


"""
cstrip-dw-script.py.

USE UNDER OWN YOUR RESPONSABILITTY

This guy tell me how to make it:
http://david.dantoine.org/

Python library to download cstrips content

/ by el tete sky /

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free
Software Foundation, either version 2 of the License, or (at your option) any
later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public License along
with this program.  If not, see <http://www.gnu.org/licenses/>.

"""

from string import digits, uppercase
from itertools import product
import sched, time
from os import path
import requests

# Change USER for your user number and execute

URL = 'http://cstrips.bitstrips.com/%s_TZH4P.png'
WAITTIME = 0.05

# --------------------------------------------------


""" download images """
def dwIMG(p_sID):
	sURL = URL % p_sID
	print sURL,
	r = requests.get(sURL)

	if r.status_code == 200:
		f = open(p_sID + '.png','wb')
		f.write(r.content)
		f.close()
		print 'OK'
	else:
		print 'NONE'


def genIDS():
	chars = digits + uppercase
	iLast = getLAST()
	iCurrent = -1
	for sID in product(chars, repeat=5):
		iCurrent += 1

		# ignore already tested IDs
		if iCurrent < iLast:
			continue

		# save each 1000 iterations
		if not iCurrent % 1000:
			savLAST(iCurrent)

		dwIMG(''.join(sID))
		time.sleep(WAITTIME)

# ----------------- recover last session
FILELAST = 'session.last'

def savLAST(p_iNum):
	f = open(FILELAST,'w')
	f.write(str(p_iNum))
	f.close()
	print "** saved session [", p_iNum, "] **"
	

def getLAST():
	if path.isfile(FILELAST):
		f = open(FILELAST,'r')
		iNum = int(f.read(), 10)
		print "recover from:", iNum
		f.close()
		return iNum
	else:
		print "process started..."
		return 0

if __name__ == '__main__':
	genIDS()
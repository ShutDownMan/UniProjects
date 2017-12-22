# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from PyQt4 import QtCore, QtGui, uic

import sys

from JustTraing import Ui_BotMainWindow

class MainWindow(QtGui.QMainWindow, Ui_BotMainWindow):

	def __init__(self, parent=None):
		super(MainWindow, self).__init__(parent)
		self.ui = Ui_BotMainWindow()
		self.ui.setupUi(self)


if __name__ == '__main__':     
	app = QtGui.QApplication(sys.argv)
	myW = MainWindow()
	myW.show()
	sys.exit(app.exec_())

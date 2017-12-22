# -*- coding: utf-8 -*-
from __future__ import unicode_literals
from Tkinter import *
from ttk import *
from classes.commands import Commands
""" GUI initializer """

class LazyBotGUI(tk.Frame):
	firefox_capabilities = None
	foxDriver = None
	page = None
	cmd = None

	def __init__(self, parent):
		self.cmd = Commands(master)

	#	root.title("Geometry Example")

	#	content = ttk.Frame(root)
	#	frame = ttk.Frame(content, borderwidth=5, width=200, height=100)

	#	welcome = ttk.Label(content, text="Welcome to LazyBot!")

	#	botStatus = ttk.Label(content, text="Bot Status: ???")

	#	stopBot = ttk.Button(content, text="Stop Bot")
	#	startBot = ttk.Button(content, text="Start Bot")

	#	startBot['command'] = StartBot

	#	content.grid(column=0, row=0)
	#	frame.grid(column=0, row=0, columnspan=3, rowspan=2)

	#	welcome.grid(column=1, row=0, sticky=(W, N), padx=10, pady=10)

	#	botStatus.grid(column=0, row=1, sticky=(W, N), padx=10, pady=10)

	#	stopBot.grid(column=2, row=10, sticky=(E, S), padx=5)
	#	startBot.grid(column=3, row=10, sticky=(E, S))

	def StartBot(self):
		cmd.open_game('','')


if __name__ == "__main__":
	pass
#	root = Tk()
#	Example(root)
#	root.mainloop()
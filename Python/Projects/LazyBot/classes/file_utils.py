# -*- coding: utf-8 -*-
from __future__ import unicode_literals

import collections
import io
from os import remove, close, walk
from tempfile import mkstemp
from shutil import move

class File_Utils():

	Master = None

	def __init__(self, master):
		self.Master = master
		print "File_Utils module loaded!\n" + str(master)
	
	def get_file_array(self, file_path):
		file = io.open(file_path, "r")
		file_array = file.readlines()
		file.close()

		return file_array

	def get_config(self, config_type):
		file_array = None
		if config_type == "Troops Carrying Capacity":
			file_array = self.get_file_array(self.Master.Bot_Dir + '\\Game\\LazyShut\\Poenari\\Configs\\Troops Carrying Capacity.txt')

		return file_array

	def get_status(self, village):
		lines = self.get_file_array(self.Master.Bot_Dir + '\\Game\\LazyShut\\Poenari\\Configs\\Villages Status.txt')
		status = {"Status name":"status"}
		index = [0]

		for index[0] in range(len(lines)):
			if village in lines[index[0]]:
				status = collections.OrderedDict(self.get_children(index, lines))
				break

		return status

	def get_children(self, index, array):
		status = collections.OrderedDict()
		index[0] += 1
		try:
			while '}' not in array[index[0]]:

				line = array[index[0]]

				if (line.replace(' ','')).strip() != "":
					if ':' in line:
						splited_line = ((line.replace('\t','')).strip()).split(':')

						if '{' in line:
							status.update({str(splited_line[0]):self.get_children(index, array)})
						else:
							status.update({str(splited_line[0]):str(splited_line[1])})

						if '[' in line:
							status.update({str(splited_line[0]):self.get_list(index, array)})
					else:
						pass

					index[0] += 1

		except:
			print "Error getting status of line " + str(array[index[0]])

		return status

	def get_list(self, index, array):
		status_list = []
		index[0] += 1
		try:
			while ']' not in array[index[0]]:
				line = array[index[0]]

				if (line.replace(' ','')).strip() != "":
					status_list.append(str(line.strip()))

					index[0] += 1

		except:
			print "Error getting list on line " + str(array[index[0]])

		return status_list



	def update_status(self, village, status, newstatus):
		file_path = self.Master.Bot_Dir + '\\Game\\LazyShut\\Poenari\\Configs\\Villages Status.txt'
		village_found = False
		hit = False
		#Create temp file
		fh, abs_path = mkstemp()
		with open(abs_path,'w') as new_file:
			with open(file_path) as old_file:
				for line in old_file:
					if village in line:
						village_found = True

					if status in line and hit == False and village_found == True:
						hit = True
						status_to_change = line.split(':')[1]
						new_file.write(line.replace(status_to_change, newstatus+'\n'))
						print status_to_change
					else:
						new_file.write(line)

					if village_found == True and line == '}':
						village_found = False
						hit = True


		if hit == True:
			print 'Pattern Found!'

		close(fh)
		#Remove original file
		remove(file_path)
		#Move new file
		move(abs_path, file_path)

		# bot.ufile.update_status("[0x00 - Village]", "Spearman", "Noup")

	def replaceline(self, file_path, pattern, subst):
		hit = False
		#Create temp file
		fh, abs_path = mkstemp()
		with open(abs_path,'w') as new_file:
			with open(file_path) as old_file:
				for line in old_file:
					if pattern in line and hit == False:
						hit = True
						new_file.write(line.replace(pattern, subst))
					else:
						new_file.write(line)

		if hit == True:
			print 'Pattern Found!'

		close(fh)
		#Remove original file
		remove(file_path)
		#Move new file
		move(abs_path, file_path)

	def removeline(self, file_path, lineToRemove):
		f = open(file_path,"r+")
		d = f.readlines()
		f.seek(0)
		hit = False
		for i in d:
			if i != lineToRemove:
				f.write(i)
			else:
				if hit == False:
					hit = True
				else:
					f.write(i)
		f.truncate()
		f.close()

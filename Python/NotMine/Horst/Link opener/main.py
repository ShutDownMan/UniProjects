import sys
import os
import re

file_links_to_open = open('anais_sbie_2013.txt', 'r');

def main():

	for line in file_links_to_open:
		print 'Trying to open ' + line;
		os.system("start \"\" " + line);
	pass

if __name__ == '__main__':
	main();
	pass
#!/usr/bin/env python

# this program counts all the lines containing foo within each file inputted.

import os
import sys

# help_function: displays the help message through the help_message.txt
def help_function():

	# open help_message.txt.
	f = open("help_message.txt",'r')

	# read and print the contents of the file to the terminal.
	print(f.read())

	# close the file.
	f.close()

# count_foo: counts the number of lines containing foo in this specific file.
def count_foo(file):

	# intialize count to zero.
	count = 0

	# open the file.
	f = open(file, 'r')

	# read each line in the file.
	for line in f:
		# if the line contains foo, print the filename and the line, and increment the count.
		if "foo" in line.lower():
			print("file: {}".format(file))
			print("line: {}".format(line))
			count += 1
	# close the file.
	f.close()

	# return the coun value.
	return(count)

# main: this is the main function.
def main(argv):
	
	# initialize number of matches to zero.
	match = 0

	# initialize help flag to 0
	help = 0

	# check the arguments.
	for arg in argv:
		# if the argument contains --help, display the help message.
		if arg.lower() == "--help":
			help_function()
			help = 1
		# else, read the file and return any matches.
		else:
			match += count_foo(arg)

	# if there are no arguments, print this.
	if len(argv) == 0 and help == 0:
		print("There are no files in the argument.")
	# else if there is only --help, do nothing after.
	elif len(argv) == 1 and help == 1:
		pass
	# else, print number of matches.
	else:
		print("Number of matches: {}".format(match))

if __name__=="__main__":
	main(sys.argv[1:])

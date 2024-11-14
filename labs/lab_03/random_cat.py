#!/usr/bin/env python
 
 # file: a simple program that reads from the command line
 
 import os
 import sys
 
 # function to count number of arguments
 def num_args(argv):
 	print("number of words is {}".format(len(argv)))
 	return True
 
 # main function
 def main(argv):
 
 	# print the number of args
 	num_args(argv)
 
 	# define whatever
 	whatever = ' '.join(argv)
 
 	# print whatever
 	print(whatever)
 
 	#return nothing
 	return(0)
 
 if __name__ == "__main__":
 	main(sys.argv[1:]) 
.
.
.
done printing.

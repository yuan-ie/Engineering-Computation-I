#!/usr/bin/env python

import sys
import argparse

def args_handler(argv):

    parser = argparse.ArgumentParser(description="Process command-line arguments.")

    parser.add_argument("-n", "--number", type=int, default=0)
    parser.add_argument("-w", "--word", type=str, required=True, help="Input a word.")
    parser.add_argument("files", nargs="+", help="Input file(s) to process.")

    args = parser.parse_args()

    return args.number, args.word, args.files

def read_file(f, n, w):

    num = n
    match = 0
    
    try:
        with open(f, "r") as file:
            print("--------------------\n--------------------\n", end="")
            lines = file.readlines()
            print("File: {}\n".format(f), end="")
            for L,line in enumerate(lines):
                if w.lower() in line.lower():  
                    num = n
                    match = 1
                    while num > 0 :
                        try:
                            if L-num >= 0:
                                print(lines[L-num], end="")
                        except:
                            continue
                        num -= 1
                    print(line.upper(), end="")
                    num = 1
                    while num < n+1:
                        try:
                            print(lines[L+num], end="")
                        except:
                            pass
                        num += 1
            if match == 0:
                print("No matches in this file.")
    except:
        print("--------------------\n--------------------\n", end="")
        print("Cannot open file: {}".format(f))

    

def main(argv):

    if len(argv) == 1:
        print("Usage: {} -n [lines] -w [word] <file1> <file2> ... <file>\n".format(argv[0]))
        exit()

    number,word,files = args_handler(argv)

    for file in files:
        read_file(file, number, word)

if __name__ == "__main__":
    main(sys.argv[:])
#!/usr/bin/env python

import sys
import pandas as pd

def num_args(argv):
    if len(argv) != 1:
        print("Usage: p02.py <file.xlsx>")
        return False
    else:
        return True

# def is_excel(file):

def main(argv):

    if num_args(argv) == True: 
        df = pd.read_excel(argv[0], header=None)
        print(df)
        print(df.shape)

if __name__ == "__main__":
    main(sys.argv[1:])
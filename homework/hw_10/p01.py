#!/usr/bin/env python
import sys

def power_loop(x:int, y:int):
    tmp = 1
    
    for power in range(y):
        tmp = tmp * x
    print("For Loop: pow({} ** {}) = {}".format(x,y,tmp))

def recursion(x:int, y:int, tmp:int, count:int):
    if y == count:
        print("Recursion: pow({} ** {}) = {}".format(x,y,tmp))
        exit()
    else:
        tmp = tmp * x
        count += 1
        recursion(x, y, tmp, count)


def main (argv):
    
    if len(argv) != 3:
        print("Usage: {} <const> <const>".format(argv[0]))
        return 1
    
    power_loop(int(argv[1]), int(argv[2]))
    recursion(int(argv[1]), int(argv[2]), 1, 0)

if __name__ == "__main__":
    main(sys.argv[:])
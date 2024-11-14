#!/usr/bin/env python

import sys
import os
import numpy as np
import pandas as pd


def main():

    # initialize zero metrices
    mat1 = np.zeros((5,5))
    mat2 = np.zeros((5,5))
    #print(mat1)

    # method 1, for loop
    # for row in range(len(mat1)):
    #     for col in range(len(mat1[0])):
    #         mat1[row,col] = 1.0
    # print(mat1)

    # method 2, colon
    mat1[:] = 1.0
    print("Matrix 1")
    print(mat1)
    print()

    mat2[:] = 10.0
    print("Matrix 2")
    print(mat2)
    print()

    # add the matrices
    print("Matrix 1 + Matrix 2")
    mat_add = mat1 + mat2
    print(mat_add)
    print()

    # subtract the matrices
    print("Matrix 2 - Matrix 1")
    mat_sub = mat2 - mat1
    print(mat_sub)
    print()

    # multiply the matrices
    print("Matrix 1 * Matrix 2")
    mat_mul = mat1 * mat2
    print(mat_mul)
    print()


main()
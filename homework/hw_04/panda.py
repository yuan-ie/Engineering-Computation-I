#!/usr/bin/env python

import os
import sys
import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import norm

def main():

	# set the mean to a value of 0
	mu = np.array([0])

	# set the covariance matrix to value of 1.0
	cov = np.array([1.0])

	# set x as a scalar which range from -10 to 10
	# x =  np.arange(-10,11,1)
	x = np.linspace(-10,10,1000)

	sigma = np.sqrt(cov)

	# function p(x)
	p1 = norm.pdf(x,mu,sigma)

	plt.plot(x,p1)
	plt.show()
	plt.savefig("univariate_gaussian_01.png")
main()

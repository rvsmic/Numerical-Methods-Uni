"""
Zadanie 4 Napisz program do graficznej prezentacji wyników uzyskanych za pomocą interpolacji Lagrange’a oraz kubicznej splajnowej.
Wykorzystaj pakiet interpolate z biblioteki SciPy.
"""

import numpy as np
import scipy.interpolate as spi
import matplotlib.pyplot as plt

def lagrange_interpolation(x, y, x_new):
    return spi.lagrange(x, y)(x_new)

def cubic_spline_interpolation(x, y, x_new):
    return spi.CubicSpline(x, y)(x_new)

def draw_plot(x, y, x_new, y_new, title):
    plt.plot(x, y, 'o', label='data')
    plt.plot(x_new, y_new, 'o', label='interpolation')
    plt.title(title)
    plt.legend()
    plt.show()


x = [-1.4, -1, 0, 1, 2, 2.2, 2.5, 2.7, 3, 3.2]
y = [11.95, 1.85, 1, 0.54, 0.17, 0.31, 0.57, 0.76, 0.97, 0.99]
x0 = 1.5;
result_1 = lagrange_interpolation(x, y, x0)
result_2 = cubic_spline_interpolation(x, y, x0)
print(result_1)
print(result_2)

draw_plot(x, y, x0, result_1, 'Lagrange interpolation')
draw_plot(x, y, x0, result_2, 'Cubic spline interpolation')
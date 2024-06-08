/*
Zadanie 4 Zaimplementuj różniczkowanie za pomocą wielomianów Lagrange’a.
Wyznacz pochodną w punkcie x = 3.5 przy następujących węzłach interpolacji: {1, 4}, {2, 10}, {3, 20}, {4, 34}, {5, 52}.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double lagrange(double *x, double *y, int n, double x0) {
    double result = 0;
    for(int i = 0; i < n; i++) {
        double temp = 1;
        for(int j = 0; j < n; j++) {
            if(j != i) {
                temp *= (x0 - x[j])/(x[i] - x[j]);
            }
        }
        result += y[i] * temp;
    }
    return result;
}

double lagrange_central_calculated_derivative(double* x, double *y, int n, double x0, double h) {
    return (lagrange(x, y, n, x0+h) - lagrange(x, y, n, x0-h))/(2*h);
}

int main() {
    double x[5] = {1, 2, 3, 4, 5};
    double y[5] = {4, 10, 20, 34, 52};
    double x0 = 3.5;

    printf("Wartosc interpolacji dla x = %f: %f\n", x0, lagrange(x, y, 5, x0));
    printf("Wartosc pochodnej dla x = %f: %f\n", x0, lagrange_central_calculated_derivative(x, y, 5, x0, 1e-2));

    return 0;
}
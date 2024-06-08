/*
Zadanie 3 Napisz program implementujący interpolację za pomocą liniowych funkcji sklejanych. Przetestuj jak wyżej.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float linear_spline(float *x, float *y, int n, float x0) {
    float result = 0;
    for(int i = 0; i < n-1; i++) {
        if(x0 >= x[i] && x0 <= x[i+1]) {
            result = y[i] + ((y[i+1] - y[i])/(x[i+1] - x[i])) * (x0 - x[i]);
            break;
        }
    }
    return result;
}

int main() {
    float x[] = {-1.4, -1, 0, 1, 2, 2.2, 2.5, 2.7, 3, 3.2};
    float y[] = {11.95, 1.85, 1, 0.54, 0.17, 0.31, 0.57, 0.76, 0.97, 0.99};
    int n = 10;
    float x0 = 1.5;
    float result = linear_spline(x, y, n, x0);
    printf("Wartosc interpolacji dla x = %f: %f\n", x0, result);
    return 0;
}

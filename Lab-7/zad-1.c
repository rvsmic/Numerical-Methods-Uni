/*
Zadanie 1 Napisz program implementujący interpolację za pomocą metody Lagrange’a. Znajdź interpolację dla punktu x = 1.5 na podstawie znanych punktów wymienionych poniżej
x = {-1.4, -1, 0,1, 2, 2.2, 2.5, 2.7, 3, 3.2}
y = {11.95,1.85,1,0.54,0.17,0.31,0.57,0.76,0.97,0.99}
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float lagrange(float *x, float *y, int n, float x0) {
    float result = 0;
    for(int i = 0; i < n; i++) {
        float temp = 1;
        for(int j = 0; j < n; j++) {
            if(j != i) {
                temp *= (x0 - x[j])/(x[i] - x[j]);
            }
        }
        result += y[i] * temp;
    }
    return result;
}

int main() {
    float x[] = {-1.4, -1, 0, 1, 2, 2.2, 2.5, 2.7, 3, 3.2};
    float y[] = {11.95, 1.85, 1, 0.54, 0.17, 0.31, 0.57, 0.76, 0.97, 0.99};
    int n = 10;
    float x0 = 1.5;
    float result = lagrange(x, y, n, x0);
    printf("Wartosc interpolacji dla x = %f: %f\n", x0, result);
    return 0;
}
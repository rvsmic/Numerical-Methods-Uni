/*
Zadanie 2 Napisz program implementujący interpolację za pomocą metody Newtona. Przetestuj jak wyżej.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float difference_quotient(float* x, float* y, int n, int i, int k) {
    if(k == 0) {
        return y[i];
    }
    return (difference_quotient(x, y, n, i+1, k-1) - difference_quotient(x, y, n, i, k-1))/(x[i+1] - x[i]);
}

float newton(float* x, float* y, int n, float x0) {
    float result = 0;
    float multiplication = 1;
    for(int i = 0; i < n; i++) {
        float temp = 1;
        for(int j = 0; j < i; j++) {
            temp *= (x0 - x[j]);
        }
        multiplication *= temp;
        result += difference_quotient(x, y, n, 0, i);
    }
    result *= multiplication;
    return result;
}

int main() {
    float x[] = {-1.4, -1, 0, 1, 2, 2.2, 2.5, 2.7, 3, 3.2};
    float y[] = {11.95, 1.85, 1, 0.54, 0.17, 0.31, 0.57, 0.76, 0.97, 0.99};
    int n = 10;
    float x0 = 1.5;
    float result = newton(x, y, n, x0);
    printf("Wartosc interpolacji dla x = %f: %f\n", x0, result);
    return 0;
}

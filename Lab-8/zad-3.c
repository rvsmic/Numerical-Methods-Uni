/*
Napisz program implementujący aproksymację średniokwadra- tową liniową dla zbioru punktów
{1.1, 2.1}, {1.4, 2.3}, {1.8, 2.9}, {2.5, 3.2}, {2.8, 3.6}, {3.0, 4.2}
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void square_approximation(float *x, float *y, int n, float *a, float *b) {
    float A = 0;
    float B = 0;
    float C = 0;
    float D = 0;
    for(int i = 0; i < 6; i++) {
        A += x[i] * y[i];
        B += x[i];
        C += y[i];
        D += x[i] * x[i];
    }
    float denominator = n * D - B * B;
    *a = (n*A - B*C) / denominator;
    *b = (C*D - A*B) / denominator;
}

int main() {
    float x[] = {1.1, 1.4, 1.8, 2.5, 2.8, 3.0};
    float y[] = {2.1, 2.3, 2.9, 3.2, 3.6, 4.2};
    int n = 6;
    float a, b;
    square_approximation(x, y, n, &a, &b);
    printf("Wartosc a aproksymacji sredniokwadratowej: %f\n", a);
    printf("Wartosc b aproksymacji sredniokwadratowej: %f\n", b);
    printf("Wartosc a*2 + b aproksymacji sredniokwadratowej: %f\n", 2*a + b);

    return 0;
}
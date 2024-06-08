/*
Zadanie 2 Napisz program implementujący rozwinięcie funkcji sinus w szereg Maclaurina.
Porównaj wyniki oraz czas wykonania z funkcją biblioteczną.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double sine(double x, float epsilon) {
    double result = 0;
    double term = 1;
    int sign = 1;
    int i = 1;
    float factorial = 1;
    float power = x;
    while(fabs(term) > epsilon) {
        term = sign * power/ factorial;
        result += term;
        sign *= -1;
        power = power * x * x;
        factorial = factorial * (2*i + 1) * (2*i);
        ++i;
    }
    return result;
}

int main() {
    double x = 1;
    int n = 100;
    float epsilon = 0.0001;
    clock_t start, end;
    double result;
    start = clock();
    result = sine(x, epsilon);
    end = clock();
    printf("Wartosc szeregu Maclaurina dla x = %f: %f\n", x, result);
    printf("Czas wykonania: %f\n", (double)(end - start)/CLOCKS_PER_SEC);
    start = clock();
    result = sin(x);
    end = clock();
    printf("Wartosc funkcji bibliotecznej dla x = %f: %f\n", x, result);
    printf("Czas wykonania: %f\n", (double)(end - start)/CLOCKS_PER_SEC);
    return 0;
}
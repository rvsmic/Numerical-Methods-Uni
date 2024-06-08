/*
Zadanie 1 Napisz program implementujący rozwinięcie funkcji eksponencjalnej w szereg Maclaurina.
Porównaj wyniki oraz czas wykonania z funkcją biblioteczną.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double exponential(double x, float epsilon) {
    double result = 1;
    double numerator = 1;
    double denominator = 1;
    double term = 1;
    int i=1;
    while(term > epsilon) {
        numerator *= x;
        denominator *= i;
        term = numerator/denominator;
        result += term;
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
    result = exponential(x, epsilon);
    end = clock();
    printf("Wartosc szeregu Maclaurina dla x = %f: %f\n", x, result);
    printf("Czas wykonania: %f\n", (double)(end - start)/CLOCKS_PER_SEC);
    start = clock();
    result = exp(x);
    end = clock();
    printf("Wartosc funkcji bibliotecznej dla x = %f: %f\n", x, result);
    printf("Czas wykonania: %f\n", (double)(end - start)/CLOCKS_PER_SEC);
    return 0;
}
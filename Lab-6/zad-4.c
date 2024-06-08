/*
Napisz program impelemntujący metode falsi. Program przetestuj dla funkcji z zadania 1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f1(float x) {
    return x*x - 4;
}

float f2(float x) {
    return sin(x) - 0.5;
}

float falsi(float (*f)(float), float a, float b, float epsilon) {
    float fa = f(a);
    float fb = f(b);
    if(fa == 0) return a;
    if(fb == 0) return b;
    if(fa * fb > 0) {
        printf("Brak zmiany znaku\n");
        return 0;
    }
    float x = ((a*fb) - (b*fa))/(fb - fa);
    float x_old = 0;
    int iteration_counter = 0;
    while(fabs(x-x_old) >= epsilon) {
        x_old = x;
        if(fa * f(x) < 0) {
            x = ((x*fa) - (a*f(x)))/(fa - f(x));
        } else {
            x = ((x*fb) - (b*f(x)))/(fb - f(x));
        }
        iteration_counter++;
    }
    printf("Liczba iteracji: %d\n", iteration_counter);
    return x;
}

int main() {
    float a1 = 0;
    float b1 = 2.2;
    float a2 = 0;
    float b2 = 2.2;
    float epsilon = pow(10, -6);
    printf("-----------------\n");
    printf("Metoda falsi dla epsilon = %f\n", epsilon);
    printf("-----------------\n");
    printf("Funkcja f1(x) = x^2 - 4\n");
    float result1 = falsi(f1, a1, b1, epsilon);
    printf("x = %f\n", result1);
    printf("f1(x) = %f\n", f1(result1));
    printf("-----------------\n");
    printf("Funkcja f2(x) = sin(x) - 0.5\n");
    float result2 = falsi(f2, a2, b2, epsilon);
    printf("x = %f\n", result2);
    printf("f2(x) = %f\n", f2(result2));
    printf("-----------------\n");
    return 0;
}
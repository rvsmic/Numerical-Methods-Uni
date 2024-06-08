/*
Napisz program impelemntujący metodę siecznych. Program przetestuj dla funkcji z zadania 1.
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

float f1_derivative(float x) {
    return 2*x;
}

float f2_derivative(float x) {
    return cos(x);
}

float f1_second_derivative(float x) {
    return 2;
}

float f2_second_derivative(float x) {
    return -sin(x);
}

float secant(float (*f)(float), float x0, float x1, float epsilon) {
    float x = x1;
    float x_prev = x0;
    float division = (f(x) * (x - x_prev)) / (f(x) - f(x_prev));
    int iteration_counter = 0;
    while(fabs(division) >= epsilon) {
        division = (f(x) * (x - x_prev)) / (f(x) - f(x_prev));
        x_prev = x;
        x = x - division;
        iteration_counter++;
    }
    printf("Liczba iteracji: %d\n", iteration_counter);
    return x;
}

int main() {
    float epsilon = pow(10, -6);
    float x0, x1;
    printf("-----------------\n");
    printf("Metoda siecznych dla epsilon = %f\n", epsilon);
    printf("-----------------\n");
    if(f1_derivative(1) * f1_second_derivative(1) < 0) {
        x0 = 2.2;
        x1 = 0;
    } else {
        x0 = 0;
        x1 = 2.2;
    }
    printf("Funkcja f1(x) = x^2 - 4\n");
    float result1 = secant(f1, x0, x1, epsilon);
    printf("x = %f\n", result1);
    printf("f1(x) = %f\n", f1(result1));
    printf("-----------------\n");
    if(f2_derivative(1) * f2_second_derivative(1) < 0) {
        x0 = 2.2;
        x1 = 0;
    } else {
        x0 = 0;
        x1 = 2.2;
    }
    printf("Funkcja f2(x) = sin(x) - 0.5\n");
    float result2 = secant(f2, x0, x1, epsilon);
    printf("x = %f\n", result2);
    printf("f2(x) = %f\n", f2(result2));
    printf("-----------------\n");
    return 0;
}
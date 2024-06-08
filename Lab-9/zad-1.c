/*
Zadanie 1 Napisz program implementujący różniczkowanie numeryczne za pomocą metody Newtona dla następujących funkcji:
a) f(x)=2x^2 +2,
b) f(x)=2x^4 −x^2 +3x−7,
c) f(x) = x^2e^x.
Oblicz błąd względny otrzymanego rozwiązania dla h = 10^−2 oraz h = 10−^4.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f1(double x) {
    return 2*x*x + 2;
}

double f2(double x) {
    return 2*x*x*x*x - x*x + 3*x - 7;
}

double f3(double x) {
    return x*x*exp(x);
}

double f1_derivative(double x) {
    return 4*x;
}

double f2_derivative(double x) {
    return 8*x*x*x - 2*x + 3;
}

double f3_derivative(double x) {
    return 2*x*exp(x) + x*x*exp(x);
}

double calculated_derivative(double (*f)(double), double x, double h) {
    return (f(x+h) - f(x))/h;
}

double relative_error(double precise, double approximate) {
    return fabs(precise - approximate)/precise;
}

int main() {
    double h1 = 1e-2;
    double h2 = 1e-4;
    double x = 3;
    printf("h1 = %f\n", h1);
    printf("\n");
    printf("f1'(x) = %f\n", f1_derivative(x));
    printf("obliczone f1'(x) = %f\n", calculated_derivative(f1, x, h1));
    printf("Błąd względny: %e\n", relative_error(f1_derivative(x), calculated_derivative(f1, x, h1)));
    printf("\n");
    printf("f2'(x) = %f\n", f2_derivative(x));
    printf("obliczone f2'(x) = %f\n", calculated_derivative(f2, x, h1));
    printf("Błąd względny: %e\n", relative_error(f2_derivative(x), calculated_derivative(f2, x, h1)));
    printf("\n");
    printf("f3'(x) = %f\n", f3_derivative(x));
    printf("obliczone f3'(x) = %f\n", calculated_derivative(f3, x, h1));
    printf("Błąd względny: %e\n", relative_error(f3_derivative(x), calculated_derivative(f3, x, h1)));

    printf("\n--------------------\n\n");

    printf("h2 = %f\n", h2);
    printf("\n");
    printf("f1'(x) = %f\n", f1_derivative(x));
    printf("obliczone f1'(x) = %f\n", calculated_derivative(f1, x, h2));
    printf("Błąd względny: %e\n", relative_error(f1_derivative(x), calculated_derivative(f1, x, h2)));
    printf("\n");
    printf("f2'(x) = %f\n", f2_derivative(x));
    printf("obliczone f2'(x) = %f\n", calculated_derivative(f2, x, h2));
    printf("Błąd względny: %e\n", relative_error(f2_derivative(x), calculated_derivative(f2, x, h2)));
    printf("\n");
    printf("f3'(x) = %f\n", f3_derivative(x));
    printf("obliczone f3'(x) = %f\n", calculated_derivative(f3, x, h2));
    printf("Błąd względny: %e\n", relative_error(f3_derivative(x), calculated_derivative(f3, x, h2)));
    return 0;
}
    
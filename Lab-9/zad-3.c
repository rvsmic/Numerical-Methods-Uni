/*
Zadanie 3 Przeprowadź obliczenia analogiczne jak w zadaniu 1. dla metod różnic skończonych:
wprzód i wstecznej trzypunktowej oraz centralnej czteropunktowej.
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

double three_point_forward_calculated_derivative(double (*f)(double), double x, double h) {
    return (((-3)*f(x)) + 4*f(x+h) - f(x+(2*h)))/(2*h);
}

double three_point_reverse_calculated_derivative(double (*f)(double), double x, double h) {
    return ((3*f(x)) - (4*f(x-h)) + f(x-(2*h)))/(2*h);
}

double four_point_central_calculated_derivative(double (*f)(double), double x, double h) {
    return (f(x-2*h) - 8*f(x-h) + 8*f(x+h) - f(x+2*h))/(12*h);
}

double central_calculated_derivative(double (*f)(double), double x, double h) {
    return (f(x+h) - f(x-h))/(2*h);
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
    printf("Trzypunktowa wprzod f1'(x) = %f\n", three_point_forward_calculated_derivative(f1, x, h1));
    printf("Błąd względny: %e\n", relative_error(f1_derivative(x), three_point_forward_calculated_derivative(f1, x, h1)));

    printf("Trzypunktowa wstecz f1'(x) = %f\n", three_point_reverse_calculated_derivative(f1, x, h1));
    printf("Błąd względny: %e\n", relative_error(f1_derivative(x), three_point_reverse_calculated_derivative(f1, x, h1)));

    printf("Czteropunktowa centralna f1'(x) = %f\n", four_point_central_calculated_derivative(f1, x, h1));
    printf("Błąd względny: %e\n", relative_error(f1_derivative(x), four_point_central_calculated_derivative(f1, x, h1)));

    printf("Centralna f1'(x) = %f\n", central_calculated_derivative(f1, x, h1));
    printf("Błąd względny: %e\n", relative_error(f1_derivative(x), central_calculated_derivative(f1, x, h1)));

    printf("\n");

    printf("f2'(x) = %f\n", f2_derivative(x));
    printf("Trzypunktowa wprzod f2'(x) = %f\n", three_point_forward_calculated_derivative(f2, x, h1));
    printf("Błąd względny: %e\n", relative_error(f2_derivative(x), three_point_forward_calculated_derivative(f2, x, h1)));

    printf("Trzypunktowa wstecz f2'(x) = %f\n", three_point_reverse_calculated_derivative(f2, x, h1));
    printf("Błąd względny: %e\n", relative_error(f2_derivative(x), three_point_reverse_calculated_derivative(f2, x, h1)));

    printf("Czteropunktowa centralna f2'(x) = %f\n", four_point_central_calculated_derivative(f2, x, h1));
    printf("Błąd względny: %e\n", relative_error(f2_derivative(x), four_point_central_calculated_derivative(f2, x, h1)));
    
    printf("Centralna f2'(x) = %f\n", central_calculated_derivative(f2, x, h1));
    printf("Błąd względny: %e\n", relative_error(f2_derivative(x), central_calculated_derivative(f2, x, h1)));

    printf("\n");
    printf("f3'(x) = %f\n", f3_derivative(x));
    printf("Trzypunktowa wprzod f3'(x) = %f\n", three_point_forward_calculated_derivative(f3, x, h1));
    printf("Błąd względny: %e\n", relative_error(f3_derivative(x), three_point_forward_calculated_derivative(f3, x, h1)));

    printf("Trzypunktowa wstecz f3'(x) = %f\n", three_point_reverse_calculated_derivative(f3, x, h1));
    printf("Błąd względny: %e\n", relative_error(f3_derivative(x), three_point_reverse_calculated_derivative(f3, x, h1)));

    printf("Czteropunktowa centralna f3'(x) = %f\n", four_point_central_calculated_derivative(f3, x, h1));
    printf("Błąd względny: %e\n", relative_error(f3_derivative(x), four_point_central_calculated_derivative(f3, x, h1)));

    printf("Centralna f3'(x) = %f\n", central_calculated_derivative(f3, x, h1));
    printf("Błąd względny: %e\n", relative_error(f3_derivative(x), central_calculated_derivative(f3, x, h1)));

    printf("\n--------------------\n\n");

    printf("h2 = %f\n", h2);
    printf("\n");

    printf("f1'(x) = %f\n", f1_derivative(x));
    printf("Trzypunktowa wprzod f1'(x) = %f\n", three_point_forward_calculated_derivative(f1, x, h2));
    printf("Błąd względny: %e\n", relative_error(f1_derivative(x), three_point_forward_calculated_derivative(f1, x, h2)));

    printf("Trzypunktowa wstecz f1'(x) = %f\n", three_point_reverse_calculated_derivative(f1, x, h1));
    printf("Błąd względny: %e\n", relative_error(f1_derivative(x), three_point_reverse_calculated_derivative(f1, x, h1)));

    printf("Czteropunktowa centralna f1'(x) = %f\n", four_point_central_calculated_derivative(f1, x, h2));
    printf("Błąd względny: %e\n", relative_error(f1_derivative(x), four_point_central_calculated_derivative(f1, x, h2)));
    
    printf("Centralna f1'(x) = %f\n", central_calculated_derivative(f1, x, h2));
    printf("Błąd względny: %e\n", relative_error(f1_derivative(x), central_calculated_derivative(f1, x, h2)));

    printf("\n");
    printf("f2'(x) = %f\n", f2_derivative(x));
    printf("Trzypunktowa wprzod f2'(x) = %f\n", three_point_forward_calculated_derivative(f2, x, h2));
    printf("Błąd względny: %e\n", relative_error(f2_derivative(x), three_point_forward_calculated_derivative(f2, x, h2)));

    printf("Trzypunktowa wstecz f2'(x) = %f\n", three_point_reverse_calculated_derivative(f2, x, h1));
    printf("Błąd względny: %e\n", relative_error(f2_derivative(x), three_point_reverse_calculated_derivative(f2, x, h1)));

    printf("Czteropunktowa centralna f2'(x) = %f\n", four_point_central_calculated_derivative(f2, x, h2));
    printf("Błąd względny: %e\n", relative_error(f2_derivative(x), four_point_central_calculated_derivative(f2, x, h2)));
    
    printf("Centralna f2'(x) = %f\n", central_calculated_derivative(f2, x, h2));
    printf("Błąd względny: %e\n", relative_error(f2_derivative(x), central_calculated_derivative(f2, x, h2)));

    printf("\n");
    printf("f3'(x) = %f\n", f3_derivative(x));
    printf("Trzypunktowa wprzod f3'(x) = %f\n", three_point_forward_calculated_derivative(f3, x, h2));
    printf("Błąd względny: %e\n", relative_error(f3_derivative(x), three_point_forward_calculated_derivative(f3, x, h2)));

    printf("Trzypunktowa wstecz f3'(x) = %f\n", three_point_reverse_calculated_derivative(f3, x, h1));
    printf("Błąd względny: %e\n", relative_error(f3_derivative(x), three_point_reverse_calculated_derivative(f3, x, h1)));

    printf("Czteropunktowa centralna f3'(x) = %f\n", four_point_central_calculated_derivative(f3, x, h2));
    printf("Błąd względny: %e\n", relative_error(f3_derivative(x), four_point_central_calculated_derivative(f3, x, h2)));
    
    printf("Centralna f3'(x) = %f\n", central_calculated_derivative(f3, x, h2));
    printf("Błąd względny: %e\n", relative_error(f3_derivative(x), central_calculated_derivative(f3, x, h2)));
    return 0;
}
    
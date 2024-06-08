/*
Zadanie 3 Zaimplementuj całkowanie numeryczne za pomocą metody Simpsona.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simpson_method(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double result1 = 0, result2 = 0;
    result1 = f(a + h/2);
    for(int i = 1; i < n; i++) {
        result1 += f(a + h * i + h/2);
        result2 += f(a + h * i);
    }
    return (h / 6) * (f(a) + 4 * result1 + 2 * result2 + f(b));
}

double f1(double x) {
    return x*x;
}

double f1_integral(double x) {
    return x*x*x/3;
}

double f2(double x) {
    return cos(x);
}

double f2_integral(double x) {
    return sin(x);
}

double f3(double x) {
    return 1/x;
}

double f3_integral(double x) {
    return log(x);
}

double relative_error(double precise, double approximate) {
    return fabs(precise - approximate)/precise;
}


int main() {
    double a1 = 0, a2 = 0, a3 = M_E;
    double b1 = 1, b2 = M_PI / 2, b3 = M_E * M_E;
    int n = 10;

    printf("Dla n = 10:\n");

    printf("  Wartosc obliczonej calki dla f(x) = x^2 na przedziale <%f, %f>: %f\n", a1, b1, simpson_method(f1, a1, b1, n));
    printf("  Wartosc dokladna: %f\n", f1_integral(b1) - f1_integral(a1));
    printf("  Blad wzgledny: %e\n", relative_error(f1_integral(b1) - f1_integral(a1), simpson_method(f1, a1, b1, n)));
    
    printf("----------\n");
    
    printf("  Wartosc obliczonej calki dla f(x) = cos(x) na przedziale <%f, %f>: %f\n", a2, b2, simpson_method(f2, a2, b2, n));
    printf("  Wartosc dokladna: %f\n", f2_integral(b2) - f2_integral(a2));
    printf("  Blad wzgledny: %e\n", relative_error(f2_integral(b2) - f2_integral(a2), simpson_method(f2, a2, b2, n)));
    
    printf("----------\n");

    printf("  Wartosc obliczonej calki dla f(x) = 1/x na przedziale <%f, %f>: %f\n", a3, b3, simpson_method(f3, a3, b3, n));
    printf("  Wartosc dokladna: %f\n", f3_integral(b3) - f3_integral(a3));
    printf("  Blad wzgledny: %e\n", relative_error(f3_integral(b3) - f3_integral(a3), simpson_method(f3, a3, b3, n)));


    printf("\n====================\n\n");
    printf("Dla n = 100:\n");
    n = 100;

    printf("  Wartosc obliczonej calki dla f(x) = x^2 na przedziale <%f, %f>: %f\n", a1, b1, simpson_method(f1, a1, b1, n));
    printf("  Wartosc dokladna: %f\n", f1_integral(b1) - f1_integral(a1));
    printf("  Blad wzgledny: %e\n", relative_error(f1_integral(b1) - f1_integral(a1), simpson_method(f1, a1, b1, n)));
    
    printf("----------\n");
    
    printf("  Wartosc obliczonej calki dla f(x) = cos(x) na przedziale <%f, %f>: %f\n", a2, b2, simpson_method(f2, a2, b2, n));
    printf("  Wartosc dokladna: %f\n", f2_integral(b2) - f2_integral(a2));
    printf("  Blad wzgledny: %e\n", relative_error(f2_integral(b2) - f2_integral(a2), simpson_method(f2, a2, b2, n)));
    
    printf("----------\n");

    printf("  Wartosc obliczonej calki dla f(x) = 1/x na przedziale <%f, %f>: %f\n", a3, b3, simpson_method(f3, a3, b3, n));
    printf("  Wartosc dokladna: %f\n", f3_integral(b3) - f3_integral(a3));
    printf("  Blad wzgledny: %e\n", relative_error(f3_integral(b3) - f3_integral(a3), simpson_method(f3, a3, b3, n)));

    return 0;
}
/*
Zadanie 4 Zmodyfikuj program z poprzedniego zadania, aby wyznaczał wszystkie pierwiastki wielomaniu (również zespolone).
*/

#include <iostream>
#include <complex>
#include <cmath>

using namespace std;
typedef complex<double> Complex;

Complex horner(Complex *a, int size,  Complex x) {
    Complex result = 0;
    for(int i = size - 1; i >= 0; --i) {
        result = result * x + a[i];
    }
    return result;
}

Complex horner_derivative(Complex *a, int size,  Complex x) {
    Complex result = 0;
    for(int i = size - 1; i >= 1; --i) {
        result = result * x + a[i] * double(i);
    }
    return result;
}

Complex horner_derivative_2(Complex *a, int size,  Complex x) {
    Complex result = 0;
    for(int i = size - 1; i >= 2; --i) {
        result = result * x + a[i] * double(i) * double(i - 1);
    }
    return result;
}

Complex laguerre(Complex *a, int size, Complex x0, double eps, int max_iter) {
    Complex horn = horner(a, size, x0);
    if (abs(horn) < eps) {
        return x0;
    }
    
    Complex G = horner_derivative(a, size, x0) / horn;
    Complex H = G * G - horner_derivative_2(a, size, x0) / horn;
    Complex s = sqrt(double(size - 1) * (Complex(size) * H - G * G));
    Complex d1 = G + s;
    Complex d2 = G - s;
    Complex denominator = (abs(d1) > abs(d2)) ? d1 : d2;
    Complex A = Complex(size) / denominator;

    int iter = 0;
    Complex x = x0 - A;
    while(iter <= max_iter && abs(A) > eps) {
        G = horner_derivative(a, size, x) / horner(a, size, x);
        H = G * G - horner_derivative_2(a, size, x) / horner(a, size, x);
        s = sqrt(double(size - 1) * (Complex(size) * H - G * G));
        d1 = G + s;
        d2 = G - s;
        denominator = (abs(d1) > abs(d2)) ? d1 : d2;
        A = Complex(size) / denominator;
        x = x - A;
        ++iter;
    }

    return x;
}

int main() {
    Complex a[4] = {-6, 11, -6, 1};
    Complex x0 = 1;
    double eps = 1e-4;
    Complex q[4];
    for(int i = 0; i < 4; ++i) {
        q[i] = a[i];
    }
    for(int i = 4; i >= 2; --i) {
        Complex result = laguerre(q, i, x0, eps, 100);
        cout<<"Pierwiastek wielomianu = "<<result<<endl;
        q[i] = a[i];
        for(int j = i-1; j >= 0; --j) {
            q[j] = a[j+1] + result * q[j+1];
        }
        for(int j=0; j < i; ++j) {
            a[j] = q[j];
        }
    }
    return 0;
}
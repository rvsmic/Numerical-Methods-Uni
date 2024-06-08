/*
Zadanie 2 Napisz program obliczający wartość pierwszej i drugiej pochodnej wielomianu w punkcie.
*/

#include <iostream>
#include <complex>

using namespace std;
typedef complex<double> Complex;

Complex horner(Complex *a, int size,  double x) {
    Complex result = 0;
    for(int i = size - 1; i >= 0; --i) {
        result = result * x + a[i];
    }
    return result;
}

Complex horner_derivative(Complex *a, int size,  double x) {
    Complex result = 0;
    for(int i = size - 1; i >= 1; --i) {
        result = result * x + a[i] * double(i);
    }
    return result;
}

Complex horner_derivative_2(Complex *a, int size,  double x) {
    Complex result = 0;
    for(int i = size - 1; i >= 2; --i) {
        result = result * x + a[i] * double(i) * double(i - 1);
    }
    return result;
}

int main() {
    Complex a[4] = {-6, 11, -6, 1};
    double x = 1;
    cout<<"Wielomian w punkcie "<<x<<" = "<<horner(a, 4, x) << endl;
    cout<<"Pierwsza pochodna w punkcie "<<x<<" = "<<horner_derivative(a, 4, x) << endl;
    cout<<"Druga pochodna w punkcie "<<x<<" = "<<horner_derivative_2(a, 4, x) << endl;
    return 0;
}
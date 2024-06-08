/*
Zadanie 1 Napisz program obliczający wartość wielomanu w punkcie z wykorzystaniem schematu Hornera.
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

int main() {
    Complex a[4] = {-6, 11, -6, 1};
    double x = 2;
    cout<<"Wielomian w punkcie "<<x<<" = "<<horner(a, 4, x) << endl;
    return 0;
}
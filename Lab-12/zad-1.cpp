/*
Zadanie 1 Zaimplementuj własny generator liczb pseudolosowych addytywny LCG oparty na następującym wzorze
Xn+1 = aXn + c mod M.
Przetestuj uzyskany generator następująco:
utwórz zbiór punktów postaci
(X0, X1), (X2, X3), ..., (Xi, Xi+1), (Xi+2, Xi+3), ...
*/

#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned int uint;

struct Point {
    uint first;
    uint second;
};

Point* generate_points(uint a, uint c, uint M, uint x0, uint size) {
    Point* points = new Point[size];
    uint x = x0;
    for(int i = 0; i < size; i += 1) {
        x = (a * x + c) % M;
        points[i].first = x;
        x = (a * x + c) % M;
        points[i].second = x;
    }
    return points;
}

int main() {
    uint a = 75;
    uint c = 74;
    uint M = pow(2, 16);
    uint x0 = 123;
    uint size = 100;
    Point* points = generate_points(a, c, M, x0, size);
    cout<<"<!DOCTYPE html>"<<endl;
    cout<<"<html>"<<endl;
    cout<<"<body>"<<endl;
    cout<<"<svg width=\"1000\" height=\"1000\" xmlns=\"http://www.w3.org/2000/svg\">"<<endl;
    for(int i=0; i < size; ++i) {
        // cout << "(" << points[i].first << ", " << points[i].second << ")" << endl;
        cout<<"<circle r=\"3\" cx=\""<<points[i].first%1000<<"\" cy=\""<<points[i].second%1000<<"\" fill=\"red\" />"<<endl;
    }
    cout<<"</html>"<<endl;
    cout<<"</body>"<<endl;
    cout<<"</svg>"<<endl;
    return 0;
}
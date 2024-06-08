/*
Zadanie 4 Napisz funkcję, która za pomocą metody Monte Carlo wyznaczy
przybliżoną wartość liczby Π. Metoda ta polega na wylosowaniu n punktów
należących do kwadratu i sprawdzeniu ich przynależności do koła.
*/

#include <iostream>

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
        points[i].first = x % 1001;
        x = (a * x + c) % M;
        points[i].second = x % 1001;
    }
    return points;
}

Point* generate_lib_points(uint size) {
    Point* points = new Point[size];
    for(int i = 0; i < size; ++i) {
        points[i].first = rand() % 1001;
        points[i].second = rand() % 1001;
    }
    return points;
}

double monte_carlo_pi(Point* points, uint radius, uint size) {
    uint inside = 0;
    for(int i = 0; i < size; ++i) {
        uint x = points[i].first;
        uint y = points[i].second;
        if(x * x + y * y <= radius * radius) {
            inside += 1;
        }
    }
    return 4.0 * inside / size;
}

int main() {
    uint a = 22695477;
    uint c = 1;
    uint M = pow(2, 31);
    uint x0 = 123;
    uint size = 100000;
    uint radius = 1000;
    Point* points = generate_points(a, c, M, x0, size);
    Point* lib_points = generate_lib_points(size);
    
    cout << "Pi: " << monte_carlo_pi(points, radius, size) << endl;
    cout << "Lib Pi: " << monte_carlo_pi(lib_points, radius, size) << endl;
    return 0;
}
/*
Zadanie 3 Przetestuj jeden z zaimplementowanych generatorów za pomocą testu monobitowego,
tzn. dla dobrego generatora liczba jedynek w ciągu 20 000 bitów powinna należeć do przedziału (9725, 10275).
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

void test_monobit(Point* points, uint size) {
    uint ones = 0;
    uint maxBitCount = 20000;
    uint x;
    for(int i=0; i < size; ++i) {
        x = points[i].first;
        for(int j=0; j < 32; ++j) {
            if(maxBitCount == 0) {
                break;
            }
            ones += (x & 1);
            x >>= 1;
            maxBitCount -= 1;
        }
        x = points[i].second;
        for(int j=0; j < 32; ++j) {
            if(maxBitCount == 0) {
                break;
            }
            ones += (x & 1);
            x >>= 1;
            maxBitCount -= 1;
        }
        if(maxBitCount == 0) {
            break;
        }
    }
    cout << "Ones: " << ones << endl;
}

void test_series(Point* points, uint size) {
    uint singles = 0;
    uint doubles = 0;
    uint triples = 0;
    uint quads = 0;
    uint quints = 0;
    uint sixes_gt = 0;
    uint maxBitCount = 20000;
    uint x, bit, series_counter = 0;
    for(int i=0; i < size; ++i) {
        x = points[i].first;
        for(int j=0; j < 32; ++j) {
            if(maxBitCount == 0) {
                break;
            }
            bit = (x & 1);
            if (bit == 1) {
                ++series_counter;
                if (series_counter == 1) {
                    ++singles;
                } else if (series_counter % 2 == 0) {
                    ++doubles;
                } else if (series_counter % 3 == 0) {
                    ++triples;
                } else if (series_counter % 4 == 0) {
                    ++quads;
                } else if (series_counter % 5 == 0) {
                    ++quints;
                } else if (series_counter > 5) {
                    ++sixes_gt;
                }
            } else {
                series_counter = 0;
            }
            x >>= 1;
            maxBitCount -= 1;
        }
        x = points[i].second;
        for(int j=0; j < 32; ++j) {
            if(maxBitCount == 0) {
                break;
            }
            bit = (x & 1);
            if (bit == 1) {
                ++series_counter;
                if (series_counter == 1) {
                    ++singles;
                } else if (series_counter % 2 == 0) {
                    ++doubles;
                } else if (series_counter % 3 == 0) {
                    ++triples;
                } else if (series_counter % 4 == 0) {
                    ++quads;
                } else if (series_counter % 5 == 0) {
                    ++quints;
                } else if (series_counter > 5) {
                    ++sixes_gt;
                }
            } else {
                series_counter = 0;
            }
            x >>= 1;
            maxBitCount -= 1;
        }
    }
    cout << "Singles: " << singles << endl;
    cout << "Doubles: " << doubles << endl;
    cout << "Triples: " << triples << endl;
    cout << "Quads: " << quads << endl;
    cout << "Quints: " << quints << endl;
    cout << "Sixes_gt: " << sixes_gt << endl;
}

int main() {
    uint a = 75;
    uint c = 74;
    uint M = pow(2, 32);
    uint x0 = 123;
    uint size = 20000 / 32 / 2;
    Point* points = generate_points(a, c, M, x0, size);
    test_monobit(points, size);
    test_series(points, size);
    return 0;
}
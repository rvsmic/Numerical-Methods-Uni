/*
Zadanie 2
Napisz program, który będzie wyliczał odległość pomiędzy dwoma punktami przestrzeni dwuwymiarowej w metrykach:
euklidesowej, Manhattan, rzece i kolejowej.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float calculate_euclidean_distance(float x1, float y1, float x2, float y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

float calculate_manhattan_distance(float x1, float y1, float x2, float y2) {
    return fabs(x2-x1) + fabs(y2-y1);
}

float calulate_maximum_distance(float x1, float y1, float x2, float y2) {
    return fmax(fabs(x2-x1), fabs(y2-y1));
}

float calculate_river_distance(float x1, float y1, float x2, float y2) {
    if(x1 == x2){
        return fabs(x2-x1);
    } else {
        return y1 + fabs(x2-x1) + y2;
    }
}

float calculate_railway_distance(float x1, float y1, float x2, float y2) {
    /*
        czy punkty sa na tej samej prostej?
        liczymy wyznacznik macierzy
        0  0  1 |0  0
        x1 y1 1 |x1 y1
        x2 y2 1 |x2 y2
    */
    float det = x1*y2 - x2*y1;
    if(abs(det) < 10<<-5) {
         return calculate_euclidean_distance(x1, y1, x2, y2);
    }
    return sqrt(x1*x1 + y1*y1) + sqrt(x2*x2 + y2*y2);
}

int main() {
    float x1 = 1, y1 = 1;
    float x2 = 3, y2 = 2;

    printf(
        "Odleglosci:\n  Euklidesowa: %f\n  Manhattan: %f\n  Maximum: %f\n  Rzeczna: %f\n  Kolejowa: %f\n", 
        calculate_euclidean_distance(x1, y1, x2, y2),
        calculate_manhattan_distance(x1, y1, x2, y2),
        calulate_maximum_distance(x1, y1, x2, y2),
        calculate_river_distance(x1, y1, x2, y2),
        calculate_railway_distance(x1, y1, x2, y2)
    );
    return 0;
}
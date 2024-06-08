/*
Zadanie 1
Napisz program pokazujący fakt, że kolejność dodawania w arytmetyce komputera nie zawsze jest przemienna.
*/

#include <stdio.h>

int main() {
    float a = 1<<25; //1000000.11;
    float b = -(1<<25); //3.03;
    float c = 1; //0.02;

    printf("(a + b) + c = %f\n", (a + b) + c);
    printf("a + (b + c) = %f\n", a + (b + c));

    return 0;
}
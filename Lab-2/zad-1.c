/*
Zadanie 1
Napisz program, który obliczy normę: euklidesową, Manhattan, maximum dla n-wymiarowego wektora.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float calculate_euclidean_norm(float* arr, int n) {
    float sum = 0.0;
    for(int i=0;i<n;++i) {
        sum += arr[i] * arr[i];
    }
    return sqrt(sum);
}

float calculate_manhattan_norm(float* arr, int n) {
    float sum = 0.0;
    for(int i=0;i<n;++i) {
        sum += fabs(arr[i]);
    }
    return sum;
}

float calculate_maximum_norm(float* arr, int n) {
    float max = 0.0;
    for(int i=0;i<n;++i) {
        if(fabs(arr[i]) > max) {
            max = fabs(arr[i]);
        }
    }
    return max;
}

int main() {
    int n = 2;
    float *arr = (float*)malloc(n);
    for(int i=0;i<n;++i) {
        arr[i] = 1;
    }
    printf(
        "Normy:\n  Euklidesowska: %f\n  Manhattan: %f\n  Maximum: %f\n", 
        calculate_euclidean_norm(arr, n),
        calculate_manhattan_norm(arr, n),
        calculate_maximum_norm(arr, n)
    );
    free(arr);
    return 0;
}
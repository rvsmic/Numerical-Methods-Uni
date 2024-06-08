/*
Zadanie 3
Napisz program, który obliczy normę: Frobeiunsa, Manhattan, maximum dla n × m-wymiarowej macierzy.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float calculate_frobenius_norm(float** arr, int n, int m) {
    float sum = 0.0;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            sum += arr[i][j] * arr[i][j];
        }
    }
    return sqrt(sum);
}

float calculate_manhattan_norm(float** arr, int n, int m) {
    float sum = 0.0;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            sum += fabs(arr[i][j]);
        }
    }
    return sum;
}

float calculate_maximum_norm(float** arr, int n, int m) {
    float max = 0.0;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(fabs(arr[i][j]) > max) {
                max = fabs(arr[i][j]);
            }
        }
    }
    return max;
}

int main() {
    int n = 2, m = 2;
    float **arr = (float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;++i) {
        arr[i] = (float*)malloc(m*sizeof(float));
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            arr[i][j] = 1;
        }
    }
    printf(
        "Normy:\n  Frobeniusa: %f\n  Manhattan: %f\n  Maximum: %f\n", 
        calculate_frobenius_norm(arr, n, m),
        calculate_manhattan_norm(arr, n, m),
        calculate_maximum_norm(arr, n, m)
    );
    for(int i=0;i<n;++i) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
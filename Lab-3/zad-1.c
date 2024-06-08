/*
Zadanie 1
Napisz funkcję zwracającą wyznacznik macierzy kwadratowej dowolnego rozmiaru.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_matrix(float** arr, int n, int m) {
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
}

float matrix_determinant(float **arr, int n, int m) {
    if(n != m) {
        return 0;
    }
    if(n == 1) {
        return arr[0][0];
    }
    if(n == 2) {
        return arr[0][0]*arr[1][1] - arr[0][1]*arr[1][0];
    }
    float result = 0;
    float **temp = (float**)malloc((n-1)*sizeof(float*));
    for(int j=0;j<n-1;++j) {
        temp[j] = (float*)malloc((n-1)*sizeof(float));
    }
    for(int i=0;i<n;++i) {
        for(int j=1;j<n;++j) {
            int idx = 0;
            for(int k=0;k<n;++k) {
                if(k == i) {
                    continue;
                } else {
                    temp[j-1][idx] = arr[j][k];
                    idx++;
                }
            }
        }
        result += arr[0][i] * pow(-1, i) * matrix_determinant(temp, n-1, m-1);
    }
    for(int i=0;i<n-1;++i) {
        free(temp[i]);
    }
    free(temp);
    return result;
}

int main() {
    int n = 4, m = 4;
    float **a = (float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;++i) {
        a[i] = (float*)malloc(m*sizeof(float));
    }
    a[0][0] = 1;
    a[0][1] = 3;
    a[0][2] = 7;
    a[0][3] = 2;
    a[1][0] = 3;
    a[1][1] = 2;
    a[1][2] = -6;
    a[1][3] = 1;
    a[2][0] = 1;
    a[2][1] = -1;
    a[2][2] = -1;
    a[2][3] = 2;
    a[3][0] = 3;
    a[3][1] = 8;
    a[3][2] = 5;
    a[3][3] = -4;
    print_matrix(a, n, m);
    printf("Wyznacznik macierzy: %f\n", matrix_determinant(a, n, m));
    return 0;
}

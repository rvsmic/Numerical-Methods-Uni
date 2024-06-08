/*
    Rozkład LU macierzy
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

float** multiply_matrices(float** a, float** b, int n, int m, int k) {
    float** result = (float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;++i) {
        result[i] = (float*)malloc(k*sizeof(float));
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<k;++j) {
            result[i][j] = 0;
            for(int l=0;l<m;++l) {
                result[i][j] += a[i][l] * b[l][j];
            }
        }
    }
    return result;
}

int main() {
    int n=8;
    float **A = (float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;++i) {
        A[i] = (float*)malloc(n*sizeof(float));
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            if(i==j) {
                A[i][j] = 11;
            } else if (i+1==j || i-1==j) {
                A[i][j] = -5;
            } else {
                A[i][j] = 0;
            }
        }
    }
    float **B = (float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;++i) {
        B[i] = (float*)malloc(1*sizeof(float));
        B[i][0] = 0;
    }
    B[0][0] = 11;
    print_matrix(A, n, n);
    printf("-----------------\n");
    print_matrix(B, n, 1);

    return 0;
}
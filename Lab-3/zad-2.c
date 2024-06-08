/*
Zadanie 2
Napisz funkcję zwracającą transpozycję macierzy dowolnego rozmiaru.
*/

#include <stdio.h>
#include <stdlib.h>

void print_matrix(float** arr, int n, int m) {
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
}

float** transpose_matrix(float** arr, int n, int m) {
    float** result = (float**)malloc(m*sizeof(float*));
    for(int i=0;i<m;++i) {
        result[i] = (float*)malloc(n*sizeof(float));
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            result[j][i] = arr[i][j];
        }
    }
    for(int i=0;i<n;++i) {
        free(arr[i]);
    }
    free(arr);
    return result;
}

int main() {
    int n = 2, m = 3;
    float **a = (float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;++i) {
        a[i] = (float*)malloc(m*sizeof(float));
    }

    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            a[i][j] = (i*3)+j;
        }
    }
    printf("Macierz wejsciowa: \n");
    print_matrix(a, n, m);
    printf("----------\n");
    a = transpose_matrix(a, n, m);
    printf("Macierz transponowana: \n");
    print_matrix(a, m, n);
    for(int i=0;i<n;++i) {
        free(a[i]);
    }
    free(a);
    return 0;
}
/*
Zadanie 4
Napisz program, który wykona mnożenie dwóch macierzy.
Kiedy działanie takie nie może zostać przeprowadzone?
Sprawdź czy mnożenie macierzy jest przemienne lub łączne?
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
    int n1 = 2, m1 = 2, n2 = 2, m2 = 2, n3 = 2, m3 = 2;
    float **a = (float**)malloc(n1*sizeof(float*));
    float **b = (float**)malloc(n2*sizeof(float*));
    float **c = (float**)malloc(n2*sizeof(float*));
    for(int i=0;i<n1;++i) {
        a[i] = (float*)malloc(m1*sizeof(float));
    }
    for(int i=0;i<n2;++i) {
        b[i] = (float*)malloc(m2*sizeof(float));
    }
    for(int i=0;i<n2;++i) {
        c[i] = (float*)malloc(m2*sizeof(float));
    }


    for(int i=0;i<n1;++i) {
        for(int j=0;j<m1;++j) {
            a[i][j] = 1;
        }
    }
    for(int i=0;i<n2;++i) {
        for(int j=0;j<m2;++j) {
            b[i][j] = 2;
        }
    }
    for(int i=0;i<n3;++i) {
        for(int j=0;j<m3;++j) {
            c[i][j] = 1;
        }
    }

    b[1][1] = 3;

    printf("Macierz A:\n");
    print_matrix(a, n1, m1);

    printf("Macierz B:\n");
    print_matrix(b, n2, m2);

    printf("Macierz C:\n");
    print_matrix(c, n3, m3);

    printf("----------------\n");

    float** result1 = multiply_matrices(a, b, n1, m1, m2);

    printf("Macierz wynikowa A*B:\n");
    print_matrix(result1, n1, m2);

    float** result2 = multiply_matrices(b, a, n2, m2, m1);

    printf("Macierz wynikowa B*A:\n");
    print_matrix(result2, n2, m1);

    float** result3 = multiply_matrices(a, c, n1, m1, m3);

    printf("Macierz wynikowa A*C:\n");
    print_matrix(result3, n1, m3);

    for(int i=0;i<n1;++i) {
        free(a[i]);
    }
    for(int i=0;i<n1;++i) {
        free(b[i]);
    }
    for(int i=0;i<n1;++i) {
        free(result1[i]);
    }
    free(a);
    free(b);
    free(result1);
    return 0;
}
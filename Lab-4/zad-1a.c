/*
Zadanie 1
Korzystając z funkcji napisanych na poprzednich zajęciach roz- wiąż następujące układy równań liniowych:
a)
x + 2y + z = −9
3x − 7y + 2z = 61
2x + 4y + 5z = −9
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

float** inverse_matrix(float** arr, int n, int m) {
    float** result = (float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;++i) {
        result[i] = (float*)malloc(m*sizeof(float));
    }
    float det = matrix_determinant(arr, n, m);
    if(det == 0) {
        return NULL;
    }
    float** temp = (float**)malloc((n-1)*sizeof(float*));
    for(int i=0;i<n-1;++i) {
        temp[i] = (float*)malloc((n-1)*sizeof(float));
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            for(int k=0;k<n;++k) {
                for(int l=0;l<n;l++) {
                    if(k!=i && l!=j) {
                        temp[k-(k>i)][l-(l>j)] = arr[k][l];
                    }
                }
            }
            result[j][i] = pow(-1, i+j) * matrix_determinant(temp, n-1, m-1) / det;
        }
    }
    for(int i=0;i<n-1;++i) {
        free(temp[i]);
    }
    free(temp);
    return result;
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
    int n=3;
    float **A = (float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;++i) {
        A[i] = (float*)malloc(n*sizeof(float));
    }
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 1;
    A[1][0] = 3;
    A[1][1] = -7;
    A[1][2] = 2;
    A[2][0] = 2;
    A[2][1] = 4;
    A[2][2] = 5;
    int m=1;
    float **B = (float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;++i) {
        B[i] = (float*)malloc(m*sizeof(float));
    }
    B[0][0] = -9;
    B[1][0] = 61;
    B[2][0] = -9;
    float **inv_A = inverse_matrix(A, n, n);
    if(inv_A == NULL) {
        printf("Macierz A jest nieodwracalna\n");
        return 0;
    }
    float **x = multiply_matrices(inv_A, B, n, n, m);
    printf("Macierz A: \n");
    print_matrix(A, n, n);
    printf("----------------\n");
    printf("Macierz odwrotna do A: \n");
    print_matrix(inv_A, n, n);
    printf("----------------\n");
    printf("Macierz B: \n");
    print_matrix(B, n, m);
    printf("----------------\n");
    printf("Rozwiazanie: \n");
    print_matrix(x, n, m);
    for(int i=0;i<n;++i) {
        free(A[i]);
        free(inv_A[i]);
        free(B[i]);
    }
    free(A);
    free(inv_A);
    free(B);
    return 0;
}
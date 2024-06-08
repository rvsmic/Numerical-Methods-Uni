/*
Zadanie 3
Napisz funkcję znajdującą macierz odwrotną do macierzy kwadratowej dowolnego rozmiaru za pomocą:
    a) rozwinięcia Laplace’a,
    b) metody Gaussa-Jordana.
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
    int n = 3, m = 3;
    float **a = (float**)malloc(n*sizeof(float*));
    for(int i=0;i<n;++i) {
        a[i] = (float*)malloc(m*sizeof(float));
    }
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 0;
    a[1][1] = 1;
    a[1][2] = 2;
    a[2][0] = 2;
    a[2][1] = 1;
    a[2][2] = 1;
    printf("Macierz wejsciowa: \n");
    print_matrix(a, n, m);
    printf("----------\n");
    float** b = inverse_matrix(a, n, m);
    if(b == NULL) {
        printf("Macierz nieodwracalna\n");
    } else {
        printf("Macierz odwrotna: \n");
        print_matrix(b, n, m);
    }
    printf("----------\n");
    float** c = multiply_matrices(a, b, n, m, m);
    printf("Iloczyn macierzy: \n");
    print_matrix(c, n, m);


    for(int i=0;i<n;++i) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);
    return 0;
}
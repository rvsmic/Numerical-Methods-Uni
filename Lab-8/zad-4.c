/*
Napisz program implementujący aproksymację średniokwadratową wielomianem drugiego stopnia dla zbioru punktów
{0, 2}, {0.5, 2.48}, {1, 2.84}, {1.5, 3}, {2, 2.91}
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_matrix(float** data, int n, int m, char* title) {
    printf("--- %s --\n", title);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%f ", data[i][j]);
        }
        printf("\n");
    }
    printf("--------------------\n");
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

void square_approximation(float *x, float *y, int n, float *a, float *b, float *c) {
    float** left_matrix = (float**)malloc(3*sizeof(float*));
    float** right_matrix = (float**)malloc(3*sizeof(float*));
    for(int i = 0; i < 3; i++) {
        left_matrix[i] = (float*)malloc(3*sizeof(float));
        right_matrix[i] = (float*)malloc(sizeof(float));
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            left_matrix[i][j] = 0;
        }
        right_matrix[i][0] = 0;
    }


    left_matrix[2][2] += n;
    for(int i = 0; i < n; i++) {
        right_matrix[2][0] += y[i];

        float power = x[i];
        left_matrix[1][2] += power;
        left_matrix[2][1] += power;
        right_matrix[1][0] += power*y[i];

        power *= x[i];
        left_matrix[0][2] += power;
        left_matrix[1][1] += power;
        left_matrix[2][0] += power;
        right_matrix[0][0] += power*y[i];

        power *= x[i];
        left_matrix[0][1] += power;
        left_matrix[1][0] += power;

        power *= x[i];
        left_matrix[0][0] += power;
    }

    print_matrix(left_matrix, 3, 3, "Lewa macierz");
    print_matrix(right_matrix, 3, 1, "Prawa macierz");
    print_matrix(inverse_matrix(left_matrix, 3, 3), 3, 3, "Macierz odwrotna");

    float **result_matrix = multiply_matrices(inverse_matrix(left_matrix, 3, 3), right_matrix, 3, 3, 1);
    print_matrix(result_matrix, 3, 1, "Wynik");
    *a = result_matrix[0][0];
    *b = result_matrix[1][0];
    *c = result_matrix[2][0];
}

int main() {
    float x[] = {0, 0.5, 1, 1.5, 2};
    float y[] = {2, 2.48, 2.84, 3, 2.91};
    int n = 5;
    float a, b, c;

    square_approximation(x, y, n, &a, &b, &c);
    printf("Wartosc a aproksymacji sredniokwadratowej: %f\n", a);
    printf("Wartosc b aproksymacji sredniokwadratowej: %f\n", b);
    printf("Wartosc c aproksymacji sredniokwadratowej: %f\n", c);
    printf("Wartosc a*2^2 + b*2 + c aproksymacji sredniokwadratowej: %f\n", a*4 + b*2 + c);
    return 0;
}
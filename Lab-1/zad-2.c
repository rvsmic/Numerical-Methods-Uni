#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float exact_sum(int n, int m) {
    return n / ((float)m+1);
}

void normal_sum_arr(float* arr, int n, int m) {
    for(int i=0;i<n;++i) {
        arr[i] = 1.0f / ((i%m + 1)*(i%m + 2));
    }
}

float sum(float *arr, int m) {
    float sum = 0.0;
    for(int i=0;i<m;i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n = 1 << 20, m = 1 << 5;
    float* arr = (float*)malloc(n);
    normal_sum_arr(arr, n, m);
    float norm_sum = sum(arr, n);
    float exact = exact_sum(n, m);
    printf("%f %f\n", norm_sum, exact);
    printf("%e blad wzgledny\n", fabs(norm_sum - exact)/ exact);
    printf("%e blad wzgledny\n", fabs(norm_sum - exact)/ exact);
    free(arr);
    return 0;
}
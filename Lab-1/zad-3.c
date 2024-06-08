#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
Algorytm Gilla-Mollera
*/
float calcualte_gill_moller_sum(float* arr, int n) {
    float s = 0.0, p=0.0, s_old=0.0;
    for(int i=0;i<n;++i) {
        s = s_old + arr[i];
        p = p + (arr[i] - (s-s_old));
        s_old = s;
    }
    return s + p;
}

/*
Algorytm Kahana
*/
float calculate_kahan_sum(float* arr, int n) {
    float e=0.0, s=0.0;
    for(int i=0; i<n; ++i) {
        float tmp = s;
        float y = arr[i]+ e;
        s = tmp + y;
        e = (tmp - s) + y;
    }
    return s;
}

float calculate_exact_sum(int n, int m) {
    return n / ((float)m+1);
}

void gen_sum_arr(float* arr, int n, int m) {
    for(int i=0;i<n;++i) {
        arr[i] = 1.0f / ((i%m + 1)*(i%m + 2));
    }
}

float calculate_normal_sum(float *arr, int m) {
    float sum = 0.0;
    for(int i=0;i<m;i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n = 1 << 20, m = 1 << 5;
    float* arr = (float*)malloc(n);
    gen_sum_arr(arr, n, m);
    float norm_sum = calculate_normal_sum(arr, n);
    float exact = calculate_exact_sum(n, m);
    float morr_sum = calcualte_gill_moller_sum(arr, n);
    float kahan_sum = calculate_kahan_sum(arr, n);
    printf("Sumy: %f %f %f %f\n\n", exact, norm_sum, morr_sum, kahan_sum);
    printf("%e blad wzgledny sumowania standardowo\n", fabs(norm_sum - exact)/ exact);
    printf("%e blad wzgledny sumowania alg. Gilla-Morrisa\n", fabs(morr_sum - exact)/ exact);
    printf("%e blad wzgledny sumowania alg. Kahana\n", fabs(kahan_sum - exact)/ exact);
    
    free(arr);
    return 0;
}
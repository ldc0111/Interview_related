/*************************************************************************
> File Name: heap_sort.cpp
> Author: 
> Mail: 
> Created Time: 2020年03月03日 星期二 00时28分58秒
************************************************************************/

#include<iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
#define swap(a,b) {\
                   __typeof(a) _t = a; a = b; b = _t;\
                  }

void heap_sort(int *arr,int n) {
    int * p = arr - 1;
    for (int i = 2; i <= n; i++) {
        int ind = i;
        while (ind > 1){
            if (p[ind] <= p[ind >> 1]) break;
            swap(p[ind],p[ind >> 1]);
            ind >>= 1;
        }
    }
    for (int i = n; i > 1; i--) {
        swap(p[i], p[1]);
        int ind = 1;
        while ((ind << 1) <= i - 1) {
            int temp = ind;
            if (p[temp] < p[ind << 1]) temp = ind << 1;
            if ((ind << 1 | 1) <= i - 1 && p[temp] < p[ind << 1 | 1]) temp = ind << 1| 1;
            if (temp == ind) break;
            swap(p[temp],p[ind]);
            ind = temp;
        }
    }
    return ;
}
void output(int *num, int n) {
    printf("arr = [");
    for (int i = 0; i< n; i++) {
        printf("%d.",num[i]);
    }
    printf("]\n");
}

int main() {
    #define MAX_N 20 
    srand(time(0));
    int arr[MAX_N];
    for (int i = 0; i < MAX_N; i++) arr[i] = rand() % 100;
    output(arr,MAX_N);
    heap_sort(arr,MAX_N);
    output(arr,MAX_N);
    return 0;
}

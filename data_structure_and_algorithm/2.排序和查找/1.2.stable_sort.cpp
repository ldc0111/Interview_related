/*************************************************************************
> File Name: 1.2.stable_sort.cpp
> Author: 
> Mail: 
> Created Time: 2020年03月02日 星期一 00时53分22秒
************************************************************************/

#include<iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

#define swap(a,b){\
    __typeof(a) _t = a;\
                  a = b;\
                  b = _t;\
                 }
void insert_sort(int *num, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j > 0 && num[j] < num[j - 1]; j--) {
            swap(num[j], num[j - 1]);
        }
    }
}


void bubble_sort(int *num,int n){
    int times = 1;
    for (int i = 1; i < n && times;i++) {
        times = 0;
        for (int j = 0; j < n - i; j++) {
            if (num[j] <= num[j + 1]) continue;
            swap(num[j],num[j + 1]);
            times++;
        }
    }
    return ;
}


void merge_sort(int *num,int l, int r){
    if (r - l <= 1) {
        if (r - l == 1 && num[l] > num[r]) swap(num[l],num[r]);
        return ;
    }
    int mid = (l + r) >> 1;
    merge_sort(num,l,mid);
    merge_sort(num,mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l,p2 = mid + 1,k = 0;
    while(p1 <= mid || p2 <= r) {
        if (p2 > r || p1 <= mid && num[p1] < num[p2]) {
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp,sizeof(int) * (r -l + 1));
    free(temp);
    return ;
}

void select_sort(int *num, int n){
    for (int i = 0; i < n - 1; i++) {
        int ind = i;
        for (int j = i + 1;j < n; j++) {
            if (num[ind] > num[j]) ind = j;
        }
        swap(num[i],num[ind]);
    }
    return ;
}

void quick_sort(int *num,int l,int r) {
    if (r <= l) return ;
    int x = l, y = r, z = num[l];
    while (x < y) {
        while (x < y && num[y] >= z) y--;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] <= z) x++;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num,l,x - 1);
    quick_sort(num,x + 1, r);
}

void output(int p[],int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d,",p[i]);
    }
    printf("]");
}

int main() {
    int arr[10]{4,2,4,6,45,28,47,85,91,74};
    //insert_sort(arr,10);
    //bubble_sort(arr,10);
    //merge_sort(arr,0,9);
    //select_sort(arr,10);
    quick_sort(arr,0,9);
    output(arr,10);


    return 0;
}

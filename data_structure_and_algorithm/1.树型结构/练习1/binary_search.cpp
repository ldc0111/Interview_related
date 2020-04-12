/*************************************************************************
	> File Name: binary_search.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月03日 星期二 01时06分31秒
 ************************************************************************/

#include<iostream>
#include <stdio.h>
using namespace std;

int binary_search(int *num,int n) {
    int head = 0,tail = n - 1,mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == n) return mid;
        else if (num[mid] > n)tail = mid - 1;
        else head = mid + 1;
    }
}

//11111000
int binary_search2(int *num, int n) {
    int head = -1, tail =n - 1,mid;
    while (head < tail) {
        mid =(head + tail + 1) >> 1;
        if (num[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

int binary_search3(int *num, int n) {
    int head = 0,tail = n,mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}

int main() {


    return 0;
}

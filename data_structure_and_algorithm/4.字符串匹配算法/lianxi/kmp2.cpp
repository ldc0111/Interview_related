/*************************************************************************
	> File Name: kmp2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月04日 星期三 10时47分12秒
 ************************************************************************/

#include<iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int kmp(const char *str,const char *pattern) {
    int len = strlen(pattern);
    int *next = (int *)malloc(sizeof(int) * len);
    next[0] = -1;
    for (int i = 1; i < len ;i++) {
        int j = next[i - 1];
        while (j != -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if (pattern[j + 1] == pattern[i]) {
            next[i] = j + 1;
        } else {
            next[i] = -1;
        }
    }
    int j = -1;
    for (int i = 0; str[i]; i++) {
        while (j != -1 && pattern[j + 1] != str[i]) j = next[j];
        if (pattern[j + 1] == str[i]) {
            j += 1;
        }
        printf("i = %d  j = %d\n",i,j);
        if (pattern[j + 1] == 0) return i - j;
    }
    return -1;
}


int main() {
    const char *str = "haerbinglilidecao";
    const char *pattern = "lili";
    printf("ind = %d\n",kmp(str,pattern));


    return 0;
}

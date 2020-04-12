/*************************************************************************
	> File Name: kmp4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月05日 星期四 10时59分32秒
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;

int kmp(const char *str,const char *pattern) {
    int len = strlen(pattern);
    int *next = (int *)malloc(sizeof(int) * len);
    next[0] = -1;
    for (int i = 1; i< len; i++) {
        int j = next[i - 1];
        while (j != -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if (pattern[j +  1] == pattern[i]) next[i] = j + 1;
        else next[i] = -1;
    }
    int j = -1;
    for (int i = 0; str[i]; i++) {
        while (j != -1 && pattern[j + 1] != str[i]) j = next[j];
        if (pattern[j + 1] == str[i]) j += 1;
        if (pattern[j + 1] == 0) return i - j;
    }
    return -1;
}

int main() {
    const char *str = "lidecaolili";
    const char *pattern = "lili";
    printf("%d \n",kmp(str,pattern));


    return 0;
}

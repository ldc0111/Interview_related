/*************************************************************************
	> File Name: kmp.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月03日 星期二 18时14分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int BF(char *str,char *partern) {
    for (int i = 0; str[i]; i++) {
        int flag = 1;
        for (int j = 0; partern[j]; j++) {
            if (str[i + j] == partern[j]) continue;
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    return -1;
}


int KMP(char *str, char *partern) {
    int *next = (int *)malloc(sizeof(int) * strlen(partern));
    next[0] = -1;
    for (int i = 1; partern[i]; i++) {
        int j = next[i - 1];
        while (j != -1 && partern[j + 1] != partern[i]) j = next[j];
        if (partern[j + 1] == partern[i]) next[i] = j + 1;
        else next[i] = -1;
    }
    int i = 0, j = -1;
    while (str[i]) {
        while (j != -1 && str[i] != partern[j + 1]) j = next[j];
        if (str[i] == partern[j + 1]) {
            j += 1;
        }
        i += 1;
        if (partern[j + 1] == 0) return i - (j + 1);
    }
    return -1;
}

int Sunday(char *str, char *partern) {
    #define BASE 128
    int ind[BASE] = {0};
    int len = strlen(partern),max_len = strlen(str);
    for (int i = 0; i < BASE; i++) ind[i] = len + 1;//1
    for (int i = 0; i < len; i++) ind[partern[i]] = len - i;//2
    for (int i = 0; i < max_len;) {
        int flag = 1;
        for (int j = 0; j < len; j++) {
            if (str[i + j] == partern[j]) continue;
            i += ind[str[i + len]];//3
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    #undef BASE
    return -1;
}

int shift_and(char *str, char *partern) {
    #define BASE 128
    int code[BASE] = {0},len = 0;
    for (len = 0;partern[len]; len++) code[partern[len]] |= (1 << len);
    int p = 0;
    for (int i = 0; str[i]; i++) {
        p = (p << 1 | 1) &code[str[i]];
        if (p & 1 << (len - 1)) return i - len + 1;
    }
    #undef BASE
    return -1;
}


int main() {


    char *str = "lidecaohaizeihaerbingddwoshishei";
    char *partern = "haerbing";
    printf("BF = %d \n",BF(str,partern));
    printf("KMP = %d \n",KMP(str,partern));
    printf("Sunday = %d \n",Sunday(str,partern));
    printf("shift_and = %d \n",shift_and(str,partern));

    return 0;
}

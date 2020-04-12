/*************************************************************************
	> File Name: trie.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月03日 星期二 21时18分26秒
 ************************************************************************/

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#define BASE_CNT 26
#define BASE 'a'
using namespace std;

typedef struct Node{
    int flag;
    struct Node *next[BASE_CNT];
}Node;
Node *getNewNode() {
    return (Node *)calloc(sizeof(Node),1);
}

void insert(Node *node,const char *str) {
    Node *p = node;
    for (int i = 0; i < str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            p->next[str[i] - BASE] = getNewNode();
        }
        p = p->next[str[i] - BASE];
    }
    p->flag = 1;
    return ;
}

int search(Node *node,const char *str) {
    Node *p = node;
    for (int i = 0; i < str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            return 0;
        }
        p = p->next[str[i] - BASE];
    }
    return p->flag;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < BASE_CNT; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}


int main() {
    Node *root = getNewNode();
    char str[100];
    int op;
    while(scanf("%d%s",&op,str) != EOF) {
        switch(op){
            case 1:{
                printf("insert %s to trie\n",str);
                insert(root,str);
            }break;
            case 2:{
                printf("search %s from trie = %d\n",str,search(root,str));
            }break;
        }
        
    }

    return 0;
}

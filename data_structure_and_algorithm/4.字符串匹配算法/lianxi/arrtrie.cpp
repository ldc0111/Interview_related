/*************************************************************************
 *  > File Name: trie.cpp
 *      > Author: 
 *          > Mail: 
 *              > Created Time: 2020年03月03日 星期二 21时18分26秒
 *************************************************************************/

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
typedef struct DATNode{
    int base, check;
}DATNode;


Node *getNewNode() {
    return (Node *)calloc(sizeof(Node),1);
}

int insert(Node *node,const char *str) {
    int cnt = 0;
    Node *p = node;
    for (int i = 0; i < str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            p->next[str[i] - BASE] = getNewNode();
            cnt += 1;
        }
        p = p->next[str[i] - BASE];
    }
    p->flag = 1;
    return cnt;
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

int getBase(Node *node,DATNode *trie) {
    int base = 1,flag = 0;
    while (!flag) {
        flag = 1;
        base += 1;
        for (int i = 0; i < 26; i++) {
            if (node->next[i] == NULL) continue;
            if (trie[base + i].check == 0) continue;
            flag = 0;
            break;
        }
    }
    return base;
}

void transform(Node *node,DATNode *trie,int ind) {
    if (node->flag) trie[ind].check = -trie[ind].check;
    trie[ind].base = getBase(node,trie);
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        trie[trie[ind].base + i].check = ind;
    }
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        transform(node->next[i],trie,trie[ind].base + i);
    }
    return ;
}

int searchDAT(DATNode * trie,const char *str) {
    int p = 1;
    for (int i = 0; str[i]; i++) {
        int delta = str[i] - 'a';
        int check = abs(trie[trie[p].base + delta].check);
        if (check - p) return 0;
        p = trie[p].base + delta;
    }
    return trie[p].check < 0;
}

int main() {
    Node *root = getNewNode();
    char str[100];
    int n,cnt = 1;
    scanf("%d", &n);
    int op;
    while(n--) {
        scanf("%s",str);
        cnt += insert(root,str);             
    }
    DATNode *trie = (DATNode *)calloc(sizeof(DATNode), cnt * 10);
    printf("cnt %d\n",cnt);
    transform(root,trie,1);
    printf("ssssssssss");
    while(scanf("%s",str) != EOF) {
        printf("search %s = %d\n", str,searchDAT(trie,str));
    }
    return 0;
 }


/*************************************************************************
	> File Name: ac.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月04日 星期三 11时20分29秒
 ************************************************************************/

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <queue>
#define BASE 26
#define BEGIN 'a'
using namespace std;

typedef struct Node{
    int flag;
    struct Node *next[BASE], *fail;
}Node;
Node *getNewNode() {
    return (Node *)calloc(sizeof(Node),1);
}

void insert(Node *root,const char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN;
        if (p->next[ind] == NULL) p->next[ind] = getNewNode();
        p = p->next[ind];
    }
    p->flag = 1;
    return ;
}


void build_ac(Node *root, int cnt) {
    queue<Node *> qu;
    root->fail = NULL;
    qu.push(root);
    while(!qu.empty()) {
        Node *now_node = qu.front();
        qu.pop();
        for (int i = 0; i < BASE; i++) {
            if (now_node->next[i] == NULL) continue;
            Node *p = now_node->fail;
            while(p && p->next[i] == NULL) p = p->fail;
            if (p == NULL) now_node->next[i]->fail = root;
            else now_node->next[i]->fail = p->next[i];
            qu.push(now_node->next[i]);
        }
    }
    return ;
}


void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;

}
int match_ac(Node *root,const char *str) {
    Node *p = root;
    int cnt = 0;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN;
        while (p && p->next[ind] == NULL) p = p->fail;
        if (p == NULL) p = root;
        else p = p->next[ind];
        Node *q = p;
        while (q) cnt += q->flag,q = q->fail;
    }
    return cnt;
}

int main() {
    Node *root = getNewNode();
    int n;
    char str[100];
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%s",str);
        insert(root,str);
        
    }
    scanf("%s",str);
    build_ac(root,cnt);
    printf("match = %d",match_ac(root,str));

    return 0;
}

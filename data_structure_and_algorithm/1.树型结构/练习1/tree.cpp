/*************************************************************************
	> File Name: tree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月02日 星期一 20时58分25秒
 ************************************************************************/

#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node * lchild, *rchild;
} Node;

Node *init(int data) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node *node) {
    if (node == NULL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}


int main() {



    return 0;
}

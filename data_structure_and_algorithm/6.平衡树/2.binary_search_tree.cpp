/*************************************************************************
	> File Name: 2.binary_search_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月04日 星期三 18时31分57秒
 ************************************************************************/

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
typedef struct Node{
    int key;
    struct Node *lchild, *rchild;
}Node;

Node *getNewNode(int key) {
    Node *p = (Node *)calloc(sizeof(Node),1);
    p->key = key;
    return p;
}


Node *insert(Node *root,int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key > key) root->lchild = insert(root->lchild,key);
    else root->rchild = insert(root->rchild,key);
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NULL) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root,int key) {
    if (root == NULL) return root;
    if (root->key > key) {
        root->lchild = erase(root->lchild,key);
    } else if (root->key < key) {
        root->rchild = erase(root->rchild,key);
    } else {
        if (root->lchild == NULL  && root->rchild == NULL) {
            free(root);
            return NULL;
        } else if(root->lchild == NULL || root->rchild == NULL){
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild,temp->key);
        }
    }
    return root;
}

int search(Node *root, int key) {
    if (root == NULL) return 0;
    if (root->key == key) return 1;
    return (root->key > key ? search(root->lchild,key) : search(root->rchild,key));
}


void clear(Node *node) {
    if (node == NULL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
}

void output(Node *root) {
    if (root == NULL) return ;
    output(root->lchild);
    printf("%d,",root->key);
    output(root->rchild);
}

int main() {
    srand(time(0));
    int op,val;
    #define MAX_OP 20 
    #define MAX_N 15
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        op = rand() % 6;
        val = rand() % MAX_N;
        switch(op) {
            case 0:{
                printf("serach %d = %d\n",val,search(root,val));
                break;
            }
            case 1:{
                printf("erase %d from BST\n",val);
                root = erase(root,val);
                break;
            }
            default:{
                printf("insert %d to BST\n",val);
                root = insert(root,val);
            }
        }
        output(root);
        printf("\n");
    }

    return 0;
}

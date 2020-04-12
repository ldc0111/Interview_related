/*************************************************************************
	> File Name: avl.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月05日 星期四 00时46分01秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX(a,b) ({\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    _a > _b ? _a : _b;\
})

typedef struct Node {
    int key;
    int height;
    struct Node *lchild,*rchild;
}Node;


Node *NIL = NULL;

Node *init(int key) {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    p->key = key;
    p->height = 1;
    p->lchild = p->rchild = NIL;
    return p;
}
__attribute__((constructor))
void init_NIL() {
    NIL  = init(0);
    NIL->height = 0;
    return ;
}

void calc_height(Node *root) {
    root->height = MAX(root->lchild->height,root->rchild->height) + 1;
    return ;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild =  root;
    calc_height(root);
    calc_height(temp);
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild =  root;
    calc_height(root);
    calc_height(temp);
    return temp;
}

Node *maintain(Node *root) {
    if (abs(root->lchild->height - root->rchild->height) <= 1) return root;
    if (root->lchild->height > root->rchild->height) {
        if (root->lchild->lchild->height < root->lchild->rchild->height){
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (root->rchild->rchild->height < root->rchild->lchild->height) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    return root;
}


Node *insert(Node *root,int key) {
    if (root == NIL) return init(key);
    if (root->key == key) return root;
    else if (root->key > key) root->lchild = insert(root->lchild,key);
    else root->rchild = insert(root->rchild,key);
    calc_height(root);
    return maintain(root);
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->lchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root,int key) {
    if (root == NIL) return root;
    if (root->key > key) {
        root->lchild = erase(root->lchild,key);
    } else if (root->key < key) {
        root->rchild = erase(root->rchild,key);
    } else {
        if (root->lchild == NIL && root->rchild == NIL) {
            free(root);
            return NIL;
        }else if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = (root->lchild != NIL ?root->lchild : root->rchild);
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild,temp->key);

        }
    }
    calc_height(root);
    return maintain(root);

}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    printf("(%d, %d, %d)\n",root->key,root->lchild->key,root->rchild->key);
    output(root->lchild);
    output(root->rchild);
}

int main() {
    int op ,val;
    Node *root = NIL;
    while (scanf("%d%d", &op,&val) != EOF) {
        switch(op) {
            case 1:root = insert(root,val);break;
            case 2:root = erase(root,val);break;
        }
        output(root);
    }
    return 0;
}

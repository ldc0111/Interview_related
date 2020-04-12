/*************************************************************************
	> File Name: 2.2.list.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月01日 星期日 15时11分01秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}*Linklist,LinkNode;

LinkNode * getNewNode(int val) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = val;
    p->next = NULL;
}

LinkNode *insert(Linklist l, int val,int ind){
    LinkNode ret, *p = &ret;
    ret.next = l;
    while(ind--){
        p = p->next;
        if (p == NULL) return l;
    }
    LinkNode *new_node = getNewNode(val);
    new_node->next = p->next;
    p->next = new_node;
    return ret.next;
}

LinkNode *Linkflip(Linklist l) {
    if (l == NULL) return l;
    LinkNode *pre = NULL, *cur = l, *ne = NULL;
    while(cur) {
        ne = cur->next;
        cur->next = pre;
        pre = cur;
        cur = ne;
    }
    return pre;
}

LinkNode * Linkflip2(LinkNode * l) {
    if (l == NULL || l->next == NULL) return l;
    LinkNode * ne = l->next;
    LinkNode * head = Linkflip2(ne);
    l->next = NULL;
    ne->next = l;

    return head;
}

void output(Linklist l) {
    printf("[");
    for (LinkNode *p = l; p ; p = p->next) {
        printf("%d, ",p->data);
    }
    printf("]\n");
}

int main(){
    LinkNode *l = NULL;
    for (int i = 0; i < 10; i++) {
        l = insert(l,i,0);
    }
    output(l);
    l = Linkflip(l);
    output(l);
    l = Linkflip2(l);
    output(l);

    return 0;
}



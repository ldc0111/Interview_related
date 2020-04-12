/*************************************************************************
	> File Name: unionset.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月04日 星期三 01时56分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct unionset{
    int *fa;
    int size;
} Unionset;


Unionset *init(int n) {
    Unionset *u = (Unionset *)calloc(sizeof(unionset), 1);
    u->fa = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i< n; i++) {
        u->fa[i] = i;
    }
    u->size = n;
    return u;
}

int find(Unionset *u,int x) {
    if (u->fa[x] != x) return find(u,u->fa[x]);
    return x;
}

int merge(Unionset *u,int a,int b) {
    int fa = find(u,a),fb = find(u,b);
    if (fa == fb) return 0;
    u->fa[fa] = fb;
    return 1;
}

void clear(Unionset *u) {
    if (u == NULL) return ;
    free(u->fa);
    free(u);
    return ;
}

void output(Unionset *u) {
    for (int i =0; i < u->size; i++) {
        printf("(%d,%d)\t",i,u->fa[i]);
        if ((i + 1) % 5 == 0 && i != 0) printf("\n");
    }
}
int main() {
    srand(time(0));
    int op,a,b;
    #define MAX_OP 20
    #define MAXN 10
    Unionset *u = init(MAXN);
    for (int i = 0; i < MAX_OP; i++) {
        op = rand() % 4;
        a = rand() % MAXN;
        b = rand() % MAXN;
        switch(op) {
            case 0: {
                printf("find %d <-> %d = %d\n",a,b,find(u,a) == find(u,b));
            }break;
            default:{
                printf("union %d <-> %d = %d\n",a,b,merge(u,a,b));
            }
        }
        output(u);
    }


    return 0;
}

#include "whole.h"

biTree CreateBiTree(biTree B){
    int value;
    printf("输入结点数据(输入0则该位置添加空结点)：\n");
    scanf("%d", &value);
    if(value == 0) return NULL;
    if(!(B = (biTree)malloc(sizeof(biNode)))) exit(-1);//内存申请失败，直接结束整个程序
    B->data = value;
    B->lChild = CreateBiTree(B->lChild);
    B->rChild = CreateBiTree(B->rChild);
    return B;

}

int PreOrderTraverse(biTree B){
    if(!B) return ERROR;
    printf("%d ", B->data);
    PreOrderTraverse(B->lChild);
    PreOrderTraverse(B->rChild);
    return OK;
}

int InOrderTraverse(biTree B){
    if(!B) return ERROR;
    stack S;
    biTree p, q;
    p = B;
    InitStack(&S);
    while(p || !IsEmptyStack(S)){
        if(p){
            Push(&S, p);
            p = p->lChild;
        }else{
            Pop(&S, &q);
            printf("%d ", q->data);
            p = q->rChild;
        }
    }
    return OK;
}

int LevelOrder(biTree B){
    biTree queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = B;
    while(front != rear){
        biTree q = queue[front++];
        printf("%d ", q->data);
        if(q->lChild) queue[rear++] = q->lChild;
        if(q->rChild) queue[rear++] = q->rChild;
    }
    return OK;
}
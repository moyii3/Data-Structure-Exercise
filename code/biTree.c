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
    if(!B) return OK;
    printf("%d ", B->data);
    PreOrderTraverse(B->lChild);
    PreOrderTraverse(B->rChild);
    return OK;
}
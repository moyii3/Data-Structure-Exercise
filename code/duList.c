#include "whole.h"

void CreateDuList(duLinkList *D, int n){
    *D = (duLinkList)malloc(sizeof(dulNode));
    (*D)->prior = NULL;
    (*D)->next = NULL;
    duLinkList r = *D;
    int i;
    for(i = 0;i < n;i++){
        duLinkList p = (duLinkList)malloc(sizeof(dulNode));
        printf("请输入第%d个节点数据：", i + 1);
        scanf("%d", &p->data);
        r->next = p;
        p->prior = r;
        p->next = NULL;
        r = p;
    }
}

int ShowDuList(duLinkList D){
    if(!D) return ERROR;
    duLinkList p = D->next;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}
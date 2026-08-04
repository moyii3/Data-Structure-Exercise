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

duLinkList searchDuListByLocation(duLinkList D, int i){
    duLinkList p = D;
    if(!p || i < 0) return NULL;
    int j = 0;
    while(p && j < i){
        p = p->next;
        j++;
    }
    return p;
}

int insertDuListNode(duLinkList D, int i, int value){
    duLinkList p = searchDuListByLocation(D, i-1);
    if(!p) return ERROR;
    duLinkList newNode = (duLinkList)malloc(sizeof(dulNode));
    if(!newNode) return ERROR;
    newNode->data = value;
    newNode->prior = p;
    if(p->next){
        p->next->prior = newNode;
        newNode->next = p->next;
        p->next = newNode;
        
    }else{
        p->next = newNode;
        newNode->next = NULL;
    }
    return OK;
}

int deleteDulistNode(duLinkList D, int i){
    duLinkList p = searchDuListByLocation(D, i);
    if(!p) return ERROR; 
    if(p->next){
        p->prior->next = p->next;
        p->next->prior = p->prior;
    }else{
        p->prior->next = NULL;
    }
    free(p);
    return OK;
}

void unionDuList(duLinkList *a, duLinkList b){
    //todo
}
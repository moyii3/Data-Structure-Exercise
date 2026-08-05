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

int GetDLEN(duLinkList D){
    if(!D) return 0;
    int len = 0;
    while(D->next){
        D = D->next;
        len++;
    }
    return len;
}

//传参为首节点地址
duLinkList unionDuList(duLinkList a, duLinkList b){
    //递归
    if(!a) return b;
    else if(!b) return a;
    else if(a->data < b->data){
        a->next = unionDuList(a->next, b);
        a->next->prior = a;
        return a;
    }else{
        b->next = unionDuList(a, b->next);
        b->next->prior = b;
        return b;
    }
}

//传参为首节点地址而非虚拟头节点
duLinkList sortDuList(duLinkList D){
    //递归
}
#include "whole.h"

int Test(LinkList L){
    if(!L){
        return ERROR;
    }       
    L->data = 0; // 设置头结点数据为0
    LinkList q = L;
    for(int i = 1; i <= 5; i++){
        LinkList p = (LinkList)malloc(sizeof(LNode));
        if(!p){
            return ERROR;
        }
        p->data = i;
        p->next = NULL;
        q->next = p; // 将新节点插入到链表末尾
        q = p; // 更新尾指针
    }
    return OK;
}

int InitList(LinkList *L){
    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L)){
        return ERROR;
    }
    (*L)->next = NULL;
    return OK;
}

int IsEmpty(LinkList L){
    if(!L){
        return 1;
    }
    return L->next == NULL? 1:0;
}

int DestroyList(LinkList *L){
    LinkList p;
    while(*L){
        p = *L;
        *L = (*L)->next;
        free(p);
    }
    return OK;
}

int ClearList(LinkList L){
    if(!L){
        return ERROR;
    }
    LinkList p, q;
    p = L->next;
    while(p){
        q = p;
        p = p->next;
        free(q);
    }
    L->next = NULL;
    return OK;
}

int ListLength(LinkList L){
    if(!L){
        return ERROR;
    }
    int length = 0;
    LinkList p = L->next;
    while(p){
        length++;
        p = p->next;
    }
    return length;
}

void ShowList(LinkList L){
    if(!L){
        return;
    }
    LinkList p = L->next;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

LinkList searchListByLocation(LinkList L, int i){
    LinkList p = L;
    int j = 0;
    while(p && j < i){
        p = p->next;
        j++;
    }
    if(!p || j > i){
        return NULL;
    }
    return p;
}

LinkList searchListByValue(LinkList L, int value){
    LinkList p = L->next;
    while(p && p->data != value){
        p = p->next;
    }
    return p;
}

int insertList(LinkList L, int i, int value){
    LinkList p = searchListByLocation(L, i - 1);
    if(!p){
        return ERROR;
    }
    LinkList newNode = (LinkList)malloc(sizeof(LNode));
    if(!newNode){
        return ERROR;
    }
    newNode->data = value;
    newNode->next = p->next;
    p->next = newNode;
    return OK;
}

int deleteList(LinkList L, int i){
    LinkList p = searchListByLocation(L, i - 1);
    if(!p){
        return ERROR;
    }
    LinkList q = p->next;
    p->next = q->next;
    free(q);
    return OK;
}
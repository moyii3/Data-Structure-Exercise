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

int ShowReverseDuList(duLinkList D){
    if(!D) return ERROR;
    while(D->next){
        D = D->next;
    }
    while(D->prior){
        printf("%d ", D->data);
        D = D->prior;
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
//从后往前合并，假设首结点后续结点已合并完成，比较两个首结点数据大小，小的作为合并后链表的首结点
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

//设立一个虚拟头结点，依次遍历ab链表，将数据小的接到合并链表尾
duLinkList MergeDuList(duLinkList a, duLinkList b){
    //迭代
    if(!a) return b;
    if(!b) return a;
    duLinkList dummyHead = (duLinkList)malloc(sizeof(dulNode));
    duLinkList p = dummyHead;
    while(a && b){
        if(a->data < b->data){
            p->next = a;
            a->prior = p;
            a = a->next;
            p = p->next;
        }else{
            p->next = b;
            b->prior = p;
            b = b->next;
            p = p->next;
        }
    }
    p->next = a ? a : b;
    (a ? a : b)->prior = p;
    return dummyHead->next;
}

duLinkList CreateLongDuList(duLinkList D){
    D = (duLinkList)malloc(sizeof(dulNode));
    D->prior = NULL;
    D->next = NULL;
    duLinkList r = D;
    int i;
    for(i = 0; i < 10000; i++){
        duLinkList p = (duLinkList)malloc(sizeof(dulNode));
        p->data = i;
        p->prior = r;
        r->next = p;
        p->next = NULL;
        r = r->next;
    }
    return D;
}

//传参为首节点地址而非虚拟头节点
duLinkList sortDuList(duLinkList D){
    //递归
    return D;
}


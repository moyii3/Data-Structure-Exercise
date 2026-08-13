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

//为链表头结点申请空间，并将头结点下一结点置空
int InitList(LinkList *L){
    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L)){
        return ERROR;
    }
    (*L)->next = NULL;
    return OK;
}

//链表全为空或链表头结点下一结点为空则返回1即为空链表
int IsEmpty(LinkList L){
    if(!L){
        return 1;
    }
    return L->next == NULL? 1:0;
}

//从链表头开始依次往后释放结点空间
int DestroyList(LinkList *L){
    LinkList p;
    while(*L){
        p = *L;
        *L = (*L)->next;
        free(p);
    }
    return OK;
}

//从头结点往后依次释放结点内存
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

//依次遍历链表结点，不断累加长度，输出最终长度
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

//依次遍历头结点之后的结点，并输出各结点数据
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

//依次遍历链表结点直到目标位置
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

//依次遍历链表结点，直到该结点的值与目标值相等或链表尾
LinkList searchListByValue(LinkList L, int value){
    LinkList p = L->next;
    while(p && p->data != value){
        p = p->next;
    }
    return p;
}

//找到插入位置前一个结点，使新结点指向其下一个结点，再使其指向新结点
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
//找到删除结点上一结点，使其指向删除结点下一结点，然后释放删除结点内存
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

// 头插法创建链表
//依次申请结点空间，输入数据后将其连接到头结点后，首结点前
void createListHead(LinkList *L, int n){
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    int i;
    for(i = n;i > 0; i--){
        LinkList p = (LinkList)malloc(sizeof(LNode));
        printf("输入第%d个节点的值: ", i);
        scanf("%d", &p->data);
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

//尾插法
//依次申请新结点空间，输入数据后将其接到链表尾
void createListR(LinkList *L, int n){
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    int i;
    LinkList r = *L;
    for(i = 0; i < n; i++){
        LinkList p = (LinkList)malloc(sizeof(LNode));
        printf("输入第%d个节点的值: ", i + 1);
        scanf("%d", &p->data);
        r->next = p;
        p->next = NULL;
        r = p;
    }
}

//递归
/*从后往前依次反转链表指向，假设函数递归已完成首结点后面结点的反转并返回了新的首结点指针，
将原首结点下一结点的下一结点指向自身，形成新尾，并断开原来指向防止成环
*/
LinkList reverseList(LinkList L){
    if(L == NULL || L->next == NULL) return L;
    LinkList newHead = reverseList(L->next);
    L->next->next = L;//假设L后若干节点已经反转（L->a<-b<-c),使a指向L
    L->next = NULL;//防止原首节点（新的尾节点）仍然指向a，形成环L-><-a<-b....
    return newHead;
}
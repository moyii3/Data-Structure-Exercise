typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

int InitList(LinkList *L);

int IsEmpty(LinkList L);

int DestroyList(LinkList *L);

int ClearList(LinkList L);

int ListLength(LinkList L);

void ShowList(LinkList L);

LinkList searchListByLocation(LinkList L, int i);

LinkList searchListByValue(LinkList L, int value);

int insertList(LinkList L, int i, int value);

int deleteList(LinkList L, int i);

void createListHead(LinkList *L, int n);//头插法创建链表

void createListR(LinkList *L, int n);//尾插法

LinkList reverseList(LinkList L);//反转链表

int Test(LinkList L);
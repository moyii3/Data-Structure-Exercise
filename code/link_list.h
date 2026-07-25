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

int Test(LinkList L);
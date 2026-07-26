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

int Test(LinkList L);
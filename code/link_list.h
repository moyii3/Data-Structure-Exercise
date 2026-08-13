typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

int InitList(LinkList *L);//链表初始化，输入链表指针，输出状态

int IsEmpty(LinkList L);//判断链表是否为空，输入链表（头结点指针），输出判空结果

int DestroyList(LinkList *L);//销毁链表，输入链表指针，输出销毁结果

int ClearList(LinkList L);//清空链表结点（除头结点），输入链表（头结点指针），输出清空结果

int ListLength(LinkList L);//确认链表长（不包含头结点），输入链表（头结点指针），输出链表长

void ShowList(LinkList L);//显示链表数据，输入链表（头结点指针），无输出

LinkList searchListByLocation(LinkList L, int i);//通过位置查找链表结点，输入链表（头结点指针）以及位置，输出结点指针

LinkList searchListByValue(LinkList L, int value);//通过值来查找链表结点，输入链表（头结点指针）以及值，输出结点指针

int insertList(LinkList L, int i, int value);//插入结点，输入链表（头结点指针），插入位置和结点值，输出插入结果

int deleteList(LinkList L, int i);//删除对应位置结点，输入链表（头结点指针）以及位置，输出删除结果

void createListHead(LinkList *L, int n);//头插法创建链表，输入链表指针以及要创建的结点数，无输出

void createListR(LinkList *L, int n);//尾插法，输入链表指针以及要创建的结点数，无输出

LinkList reverseList(LinkList L);//反转链表，输入链表首结点指针，输出反转后链表新首结点指针

int Test(LinkList L);//测试用
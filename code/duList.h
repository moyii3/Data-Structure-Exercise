typedef struct dulNode{
    int data;
    struct dulNode *prior, *next;
    
}dulNode, *duLinkList;

void CreateDuList(duLinkList *D, int n);

int ShowDuList(duLinkList D);

duLinkList searchDuListByLocation(duLinkList D, int i);

int insertDuListNode(duLinkList D, int i, int value);

int deleteDulistNode(duLinkList D, int i);

int GetDLEN(duLinkList D);//获取链表长（不记头结点

duLinkList unionDuList(duLinkList a, duLinkList b);//合并两个非递减双链表

duLinkList sortDuList(duLinkList D);//排序算法
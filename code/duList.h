typedef struct dulNode{
    int data;
    struct dulNode *prior, *next;
    
}dulNode, *duLinkList;

void CreateDuList(duLinkList *D, int n);

int ShowDuList(duLinkList D);

int ShowReverseDuList(duLinkList D);//反向显示双链表

duLinkList searchDuListByLocation(duLinkList D, int i);

int insertDuListNode(duLinkList D, int i, int value);

int deleteDulistNode(duLinkList D, int i);

int GetDLEN(duLinkList D);//获取链表长（不记头结点

duLinkList unionDuList(duLinkList a, duLinkList b);//合并两个非递减双链表(递归)

duLinkList MergeDuList(duLinkList a, duLinkList b);//迭代合并两个非递减双链表

duLinkList sortDuList(duLinkList D);//排序算法

duLinkList CreateLongDuList(duLinkList D);//自动生成一个含10000结点的双链表
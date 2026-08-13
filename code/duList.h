typedef struct dulNode{
    int data;
    struct dulNode *prior, *next;
    
}dulNode, *duLinkList;

void CreateDuList(duLinkList *D, int n);//创建双链表，输入链表指针以及要创建的结点数，无输出

int ShowDuList(duLinkList D);//依次显示链表结点数据，输入链表（头结点指针），输出执行结果

int ShowReverseDuList(duLinkList D);//反向显示双链表，输入链表（头结点指针），输出执行结果

duLinkList searchDuListByLocation(duLinkList D, int i);//通过位置查找链表结点，输入链表以及位置，输出目标结点指针

int insertDuListNode(duLinkList D, int i, int value);//插入结点

int deleteDulistNode(duLinkList D, int i);//通过位置删除结点

int GetDLEN(duLinkList D);//获取链表长（不记头结点

duLinkList unionDuList(duLinkList a, duLinkList b);//合并两个非递减双链表(递归)

duLinkList MergeDuList(duLinkList a, duLinkList b);//迭代合并两个非递减双链表

duLinkList sortDuList(duLinkList D);//排序算法

duLinkList CreateLongDuList(duLinkList D);//自动生成一个含10000结点的双链表
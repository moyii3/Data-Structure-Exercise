typedef struct dulNode{
    int data;
    struct dulNode *prior, *next;
    
}dulNode, *duLinkList;

void CreateDuList(duLinkList *D, int n);

int ShowDuList(duLinkList D);

duLinkList searchDuListByLocation(duLinkList D, int i);

int insertDuListNode(duLinkList D, int i, int value);

int deleteDulistNode(duLinkList D, int i);

void unionDuList(duLinkList *a, duLinkList b);
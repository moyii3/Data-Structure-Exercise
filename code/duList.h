typedef struct dulNode{
    int data;
    struct dulNode *prior, *next;
    
}dulNode, *duLinkList;

void CreateDuList(duLinkList *D, int n);

int ShowDuList(duLinkList D);
typedef struct biNode{
    int data;
    struct biNode *lChild, *rChild, *parent;
}biNode, *biTree;

biTree CreateBiTree(biTree B);//先根顺序创建一个二叉树

int PreOrderTraverse(biTree B);//先序遍历一个二叉树
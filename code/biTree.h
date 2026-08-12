typedef struct biNode{
    int data;
    struct biNode *lChild, *rChild, *parent;
}biNode, *biTree;

biTree CreateBiTree(biTree B);//先根顺序创建一个二叉树（递归

int PreOrderTraverse(biTree B);//先序遍历一个二叉树（递归

int InOrderTraverse(biTree B);//中序遍历一个二叉树（迭代法实现手动栈

int LevelOrder(biTree B);//层序遍历一个二叉树（简易队列版

int PostOrderTraverse(biTree B);//后序遍历二叉树（双栈法
typedef struct biNode{
    int data;
    struct biNode *lChild, *rChild, *parent;
}biNode, *biTree;

biTree CreateBiTree(biTree B);//先根顺序创建一个二叉树（递归)，输入二叉树（根结点指针），输出创建好后的二叉树

int PreOrderTraverse(biTree B);//先序遍历一个二叉树（递归），输入二叉树，输出各结点数据

int InOrderTraverse(biTree B);//中序遍历一个二叉树（迭代法实现手动栈），输入二叉树，输出各结点数据

int LevelOrder(biTree B);//层序遍历一个二叉树（简易队列版），输入二叉数，输出各结点数据，返回执行结果

int PostOrderTraverse(biTree B);//后序遍历二叉树（双栈法）
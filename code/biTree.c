#include "whole.h"

//先建立根结点，接着建立左子树，假设左子树建立完成，则连接到根结点的左孩子，接着同样建立右子数
biTree CreateBiTree(biTree B){
    int value;
    printf("输入结点数据(输入0则该位置添加空结点)：\n");
    scanf("%d", &value);
    if(value == 0) return NULL;
    if(!(B = (biTree)malloc(sizeof(biNode)))) exit(-1);//内存申请失败，直接结束整个程序
    B->data = value;
    B->lChild = CreateBiTree(B->lChild);
    B->rChild = CreateBiTree(B->rChild);
    return B;

}


//先遍历根结点，接着递归遍历其左子树，再递归遍历右子树
int PreOrderTraverse(biTree B){
    if(!B) return ERROR;
    printf("%d ", B->data);
    PreOrderTraverse(B->lChild);
    PreOrderTraverse(B->rChild);
    return OK;
}

//先遍历左子树，将结点依次入栈，接着再依次出栈同时依次同样按中序遍历其右子树
int InOrderTraverse(biTree B){
    if(!B) return ERROR;
    stack S;
    biTree p, q;
    p = B;
    InitStack(&S);
    while(p || !IsEmptyStack(S)){
        if(p){
            Push(&S, p);
            p = p->lChild;
        }else{
            Pop(&S, &q);
            printf("%d ", q->data);
            p = q->rChild;
        }
    }
    return OK;
}

//将根结点入队，接着出队，将出队结点左孩子与右孩子依次再入队出队，循环到队为空时
int LevelOrder(biTree B){
    biTree queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = B;
    while(front != rear){
        biTree q = queue[front++];
        printf("%d ", q->data);
        if(q->lChild) queue[rear++] = q->lChild;
        if(q->rChild) queue[rear++] = q->rChild;
    }
    return OK;
}

//先将根结点入栈S1，接着再出栈入栈S2，同时将其按先左后右孩子的顺序入栈S1，循环直到原二叉树结束，最后依次对栈S2进行出栈
int PostOrderTraverse(biTree B){
    if(!B) return ERROR;
    stack S1, S2;
    biTree p;
    p = B;
    InitStack(&S1);
    InitStack(&S2);
    while(p){
        Push(&S2, p);
        if(p->lChild) Push(&S1, p->lChild);
        if(p->rChild) Push(&S1, p->rChild);
        Pop(&S1, &p);
    }
    while(!IsEmptyStack(S2)){
        Pop(&S2, &p);
        printf("%d ", p->data);
    }
    return OK;
}
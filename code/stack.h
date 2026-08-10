typedef struct stackNode{
    struct biNode* node;
    struct stackNode *next;
}stackNode,*stack;

int InitStack(stack* s);//栈初始化

int Push(stack* s, biNode* b);//入栈

int Pop(stack* s, biTree* b);//出栈

int IsEmptyStack(stack s);//判断栈是否为空
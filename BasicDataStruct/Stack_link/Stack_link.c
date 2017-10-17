#include "Stack_link.h"



int Stack_Empty(Link_stack *Stack)
{
    if(Stack->Rear == NULL)
    {
        //this means the Stack is empty.
        return EMPTY;
    }
    else
        return NOT_EMPTY;
}

Link_stack* Create_LinkStack()
{
    //QNode *Node;
    Link_stack *Stack;
    //Node = (QNode *)malloc(sizeof(QNode));
    //Node->next = NULL;
    Stack = (Link_stack *)malloc(sizeof(Link_stack));
    Stack->Front = NULL;
    Stack->Rear = NULL;
    return Stack;
}

void Link_Push(float data, Link_stack *Stack)
{
    QNode *Node = (QNode *)malloc(sizeof(QNode));
    Node->data = data;
    Node->next = Stack->Rear;
    Stack->Rear = Node;

}

int Link_Pop(Link_stack *Stack)
{
    if(Stack_Empty(Stack) == EMPTY)
        return -1;
    else
    {
        QNode *Node;
        Node = Stack->Rear;
        //这里可能有内存泄露的问题感觉
        if(Stack->Rear->next == NULL)
        {
            //这里是为了避免只有一个元素的情况
            Stack->Rear = NULL;
        }
        else
            Stack->Rear = Node->next;
        free(Node);
        return 0;
    }
}

int Delete_LinkStack(Link_stack *Stack)
{
    if(Stack_Empty(Stack) == NOT_EMPTY)
    {
        while(Stack_Empty(Stack) == NOT_EMPTY)
        {
            Link_Pop(Stack);
        }
    }

    free(Stack);
    return 0;
}

void Show_Stack(Link_stack *Stack)
{
    Link_stack temp;
    temp.Front = NULL;
    temp.Rear = NULL;
    temp.Front = Stack->Front;
    temp.Rear = Stack->Rear;
    while(Stack_Empty(&temp) == NOT_EMPTY)
    {
        printf("%f\n", temp.Rear->data);
        temp.Rear = temp.Rear->next;
    }
}


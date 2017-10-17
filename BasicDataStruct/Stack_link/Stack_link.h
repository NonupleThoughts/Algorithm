#ifndef Stack_link
#define Stack_link


#include "stdio.h"
#include "stdlib.h"

#define EMPTY 1
#define NOT_EMPTY 0

//the Node of the stack
typedef struct node_stack
{
    float data;
    struct node_stack* next;

}QNode;

//the pointer
typedef struct link_stack
{
    QNode *Front;
    QNode *Rear;

}Link_stack;


int Stack_Empty(Link_stack *Stack);
Link_stack* Create_LinkStack();
void Link_Push(float data, Link_stack *Stack);
int Link_Pop(Link_stack *Stack);
int Delete_LinkStack(Link_stack *Stack);
void Show_Stack(Link_stack *Stack);


#endif  //Stack_link

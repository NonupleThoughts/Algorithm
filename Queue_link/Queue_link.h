#ifndef Queue_link
#define Queue_link


#include "stdio.h"
#include "stdlib.h"

#define EMPTY 1
#define NOT_EMPTY 0

//the Node of the queue
typedef struct node_queue
{
    float data;
    struct node_queue* next;

}QNode;

//the pointer
typedef struct link_queue
{
    QNode *Front;
    QNode *Rear;

}Link_queue;


int Queue_Empty(Link_queue *Queue);
Link_queue* Create_LinkQueue();
void Link_Enqueue(float data, Link_queue *Queue);
int Link_Dequeue(Link_queue *Queue);
int Delete_LinkQueue(Link_queue *Queue);
void Show_Queue(Link_queue *Queue);


#endif

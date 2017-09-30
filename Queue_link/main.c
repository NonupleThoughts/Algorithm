/*
* Implement a Queue with linked lists
*
* By Cong
* 2017/9/27
*/

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

int Queue_Empty(Link_queue *Queue)
{
    if(Queue->Rear == NULL)
    {
        //this means the Queue is empty.
        return EMPTY;
    }
    else
        return NOT_EMPTY;
}

Link_queue* Create_LinkQueue()
{
    //QNode *Node;
    Link_queue *Queue;
    //Node = (QNode *)malloc(sizeof(QNode));
    //Node->next = NULL;
    Queue = (Link_queue *)malloc(sizeof(Link_queue));
    Queue->Front = NULL;
    Queue->Rear = NULL;
    return Queue;
}

void Link_Enqueue(float data, Link_queue *Queue)
{
    QNode *Node = (QNode *)malloc(sizeof(QNode));
    Node->data = data;
    Node->next = Queue->Rear;
    Queue->Rear = Node;

}

int Link_Dequeue(Link_queue *Queue)
{
    if(Queue_Empty(Queue) == EMPTY)
        return -1;
    else
    {
        QNode *Node;
        Node = Queue->Rear;
        //这里可能有内存泄露的问题感觉
        if(Queue->Rear->next == NULL)
        {
            //这里是为了避免只有一个元素的情况
            Queue->Rear = NULL;
        }
        else
            Queue->Rear = Node->next;
        free(Node);
        return 0;
    }
}

int Delete_LinkQueue(Link_queue *Queue)
{
    if(Queue_Empty(Queue) == NOT_EMPTY)
    {
        while(Queue_Empty(Queue) == NOT_EMPTY)
        {
            Link_Dequeue(Queue);
        }
    }

    free(Queue);
    return 0;
}

void Show_Queue(Link_queue *Queue)
{
    Link_queue temp;
    temp.Front = NULL;
    temp.Rear = NULL;
    temp.Front = Queue->Front;
    temp.Rear = Queue->Rear;
    while(Queue_Empty(&temp) == NOT_EMPTY)
    {
        printf("%f\n", temp.Rear->data);
        temp.Rear = temp.Rear->next;
    }
}


int main()
{
    //printf("hello world\n");
    Link_queue *Queue;
    int i = 0;
    Queue = Create_LinkQueue();
    for(i = 0; i < 2; i += 1)
    {
        Link_Enqueue((float)i, Queue);
    }
    Show_Queue(Queue);
    Delete_LinkQueue(Queue);

    return 0;
}

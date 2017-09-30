/*
* Implement a Queue with linked lists
*
* By Cong
* 2017/9/27
*/

#include "stdio.h"
#include "stdlib.h"
#include "Queue_link.h"

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

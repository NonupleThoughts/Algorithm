/*
* Implement a Stack with linked lists
*
* By Cong
* 2017/9/27
*/

#include "stdio.h"
#include "stdlib.h"
#include "Stack_link.h"

int main()
{
    //printf("hello world\n");
    Link_stack *Stack;
    int i = 0;
    Stack = Create_LinkStack();
    for(i = 0; i < 2; i += 1)
    {
        Link_Push((float)i, Stack);
    }
    Show_Stack(Stack);
    Delete_LinkStack(Stack);

    return 0;
}

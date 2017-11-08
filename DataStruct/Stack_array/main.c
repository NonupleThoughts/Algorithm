/*
* Implement a Stack with resizing array
*
* By Cong
* 2017/10/17
*/

#include <stdio.h>
#include <stdlib.h>
#include "Stack_array.h"




int main()
{
    printf("Hello world!\n");
    Array_stack* a;
    a = Create_ArrayStack();

    Array_Push(3.0f,a);
    Array_Push(3.4f,a);
    Array_Push(3.2f,a);
    Array_Push(3.7f,a);
    Array_Push(3.8f,a);
    Array_Push(3.9f,a);
    Show_Stack(a);
    Array_Pop(a);
    Array_Pop(a);
    Array_Pop(a);
    Array_Pop(a);
    Array_Pop(a);
    Show_Stack(a);
    Delete_ArrayStack(a);
    return 0;
}

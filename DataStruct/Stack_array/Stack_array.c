#include "Stack_array.h"


Array_stack* Create_ArrayStack()
{
    Array_stack *Stack = (Array_stack*)malloc(sizeof(Array_stack));
    Stack->size        = def_size;
    Stack->pointer     = (def_type*)malloc((Stack->size) * sizeof(def_type));
    Stack->position    = 0;

    if(Stack == NULL || Stack->pointer == NULL)
        return NULL;
    else
        return Stack;
/*
    //for test
    int count_i = 0;
    // the default value is 0

    else
    {
        for(count_i = 0; count_i < def_size; count_i += 1)
        {
            Stack->position = count_i + 1;
            Stack->pointer[Stack->position] = 0.0f;
            return Stack;
        }
    }
*/
}

int Stack_Empty(Array_stack* Stack)
{
    return Stack->position;
}

status Resize_ArrayStack(Array_stack* Stack, int size)
{
    def_type* cache = (def_type*)malloc(Stack->position * sizeof(def_type));
    if(cache == NULL)
        return fail;
    int count = 0;
    for(count = 0; count < Stack->position; count += 1)
        cache[count] = Stack->pointer[count];

    free(Stack->pointer);
    Stack->pointer = (def_type*)malloc(size * sizeof(def_type));
    if(Stack->pointer == NULL)
    {
        free(cache);
        return fail;
    }
    for(count = 0; count < Stack->position; count += 1)
        Stack->pointer[count] = cache[count];
    Stack->size = size;
    free(cache);
    return success;
}

status Array_Push(def_type data, Array_stack* Stack)
{
    if(Stack->size <= Stack->position)
    {
        //the stack is full
        if(Resize_ArrayStack(Stack, 2 * Stack->size) == fail)
            return fail;
    }
    Stack->pointer[Stack->position] = data;
    Stack->position += 1;
    return success;
}

status Array_Pop(Array_stack* Stack)
{
    if(Stack_Empty != EMPTY)
    {
        Stack->position -= 1;
        if(Stack->size >= Stack->position * 4)
            Resize_ArrayStack(Stack, Stack->size / 2);
        return success;
    }
    else
        return fail;

}

int Delete_ArrayStack(Array_stack *Stack)
{
    //it seem to be that there is no need to judge weather the Stack is empty
    //if(Stack_Empty(Stack) != EMPTY)
    free(Stack->pointer);
    free(Stack);
}

void Show_Stack(Array_stack *Stack)
{
    int count_i = 0;
    for(count_i = 0; count_i < Stack->position; count_i += 1)
        printf("%f\n", Stack->pointer[count_i]);
}


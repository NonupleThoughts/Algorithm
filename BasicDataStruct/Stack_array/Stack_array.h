#ifndef Stack_array
#define Stack_array

#include "stdio.h"
#include "stdlib.h"

#define def_size  3
#define def_type  float

#define status  int
#define success 0
#define fail   -1

#define EMPTY   0


//the pointer
typedef struct Array_stack
{
    def_type *pointer;
    int size;
    //the number of effective elements
    //and the position of current element
    int position;

}Array_stack;


Array_stack* Create_ArrayStack();
int Stack_Empty(Array_stack* Stack);
status Resize_ArrayStack(Array_stack* Stack, int size);
status Array_Push(def_type data, Array_stack* Stack);
status Array_Pop(Array_stack* Stack);
int Delete_ArrayStack(Array_stack* Stack);
void Show_Stack(Array_stack *Stack);
#endif // Stack_array

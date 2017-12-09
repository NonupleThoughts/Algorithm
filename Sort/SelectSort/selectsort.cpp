#include "selectsort.h"
#include "iostream"

#define max
/*
*   if max is defined, this function will find the max of the arr
*   if not this function will find the min of the arr
*/
int find(float *arr, int start, int size)
{
    int count_i  = start;
    int position = start;
    for(count_i = start, position = start; count_i < size; count_i += 1)
    {
#ifdef max
        //find the max of arr
        //in order to keep the stablity of sort, choose "<" instead of "<=" there
        if(arr[position] < arr[count_i])
        {
            position = count_i;
        }
#else
        //find the min of arr
        //in order to keep the stablity of sort, choose ">" instead of "=>" there
        if(arr[position] > arr[count_i])
        {
            position = count_i;
        }
#endif
    }
    return position;
}



inline void swap(float *arr, int num1, int num2)
{
    //This may be useless beacuse 1.0f may not be equal to 1.0f
    //if(arr[num1] == arr[num2])
    //    return;
    if(num1 != num2)
    {
        float temp;
        temp = arr[num1];
        arr[num1] = arr[num2];
        arr[num2] = temp;
    }
}

void selectsort(float *arr, int size)
{
    int count_i = 0;
    int swap_target = 0;
    for(count_i = 0; count_i < size; count_i += 1)
    {
        swap_target = find(arr, count_i, size);
        swap(arr, count_i, swap_target);
    }

}

#include "insertsort.h"
#include <iostream>

/*
//method 1
//from small to large
void insertsort(datatype *dataset, int size)
{
    int count_i = 0;
    int count_j = 0;
    int count_sort = 0;     //data that have been sort
    datatype cache;
    for(count_i = 1; count_i < size; count_i += 1)
    {
        //find the data from front
        for(count_sort = 0; count_sort < count_i; count_sort += 1)
        {
            //compare the from pos 0 to pos count_i - 1
            if(dataset[count_i] < dataset[count_sort])
            {
                cache = dataset[count_i];
                //move backward
                for(count_j = count_i; count_j > count_sort; count_j -= 1)
                {
                    dataset[count_j] = dataset[count_j - 1];
                }
                dataset[count_sort] = cache;
                break;
            }
        }
    }
}
*/

//method 2
void insertsort(datatype *dataset, int size)
{
    int count_i = 0;
    int count_j = 0;
    int count_sort = 0;     //data that have been sort
    datatype cache;
    for(count_i = 1; count_i < size; count_i += 1)
    {
        cache = dataset[count_i];
        //find data from rear
        for(count_j = count_i - 1; count_j >= 0 && cache < dataset[count_j]; count_j -= 1)
        {
            //move backward
            dataset[count_j + 1] = dataset[count_j];
        }
        dataset[count_j + 1] = cache;
    }
}

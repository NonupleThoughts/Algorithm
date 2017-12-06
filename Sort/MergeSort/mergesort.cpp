
#include "iostream"
#include "mergesort.h"

using namespace std;

/*
*   using recursion to divide the set of data to some sublists and
*   each containing 1 element, then merge it.
*   besides the sortset is a cache of the data which has been sorted
*/
void Divide(float *dataset, int first, int last, float *sortset)
{
    int mid = (first + last) / 2;

    if(first < last)
    {
        Divide(dataset, first, mid, sortset);
        Divide(dataset, mid + 1, last, sortset);
        Merge(dataset, first, mid, last, sortset);

    }
}

void Merge(float *dataset,int first, int mid, int last, float *sortset)
{
    int a_first = first,   a_last = mid;
    int b_first = mid + 1, b_last = last;

    //this is the number of data which has added to sortset
    int num = 0;

    for(; a_first <= a_last && b_first <= b_last;)
    {
        if(dataset[a_first] > dataset[b_first])
        {
            sortset[num] = dataset[b_first];
            b_first += 1;
        }
        else
        {
            sortset[num] = dataset[a_first];
            a_first += 1;
        }
        num += 1;
    }

    //after analyzing, a > a_last and b > b_last will not exist at the same time
    if(a_first > a_last)
    {
        for(;b_first <= b_last; b_first += 1)
        {
            sortset[num] = dataset[b_first];
            num += 1;
        }
    }
    else if(b_first > b_last)
    {
        for(;a_first <= a_last; a_first += 1)
        {
            sortset[num] = dataset[a_first];
            num += 1;
        }
    }

    //put data which has been sorted into the previous array
    for(int i = 0; i < num; i += 1)
    {
        dataset[first + i] = sortset[i];
    }
}

void MergeSort(float *dataset, int size)
{
    float *sortset;
    sortset = new float[size];

    Divide(dataset, 0, size - 1, sortset);

    delete []sortset;
}


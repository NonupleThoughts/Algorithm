/*
*   This is implementation for MergeSort which uses recursion to achieve it.
*   Wrote by Cong
*   2017.12.6
*/


#include "iostream"
#include "mergesort.h"

using namespace std;

int main()
{
    float a[4] = {4, 3, 2, 1};
    MergeSort(a, 1);
    for(int i = 0; i < 4; i += 1)
        cout << a[i] << endl;
    return 0;
}

/*  This is implementation for SelectSort
*   Wrote by Cong
*   2017.12.9
*/


#include "iostream"
#include "selectsort.h"

using namespace std;

#define size 5
int main()
{
    float a[size] = {4, 3, 7, 2, 1};

    selectsort(a, size);

    for(int i = 0; i < size; i += 1)
        cout << a[i] << endl;

    return 0;
}


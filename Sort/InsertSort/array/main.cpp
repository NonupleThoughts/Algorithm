/*
*   This is implementation for InsertSort which use array
*   Wrote by Cong
*   2017.12.27
*/

#include <iostream>
#include "insertsort.h"

using namespace std;

#define size 10
int main()
{
    int aaa[size] = {3, 1, 5, 4, 6, 2, 7, 9, 0, 8};
    int *a = &aaa[0];
    insertsort(a, size);
    for(int count_i = 0; count_i < size; count_i += 1)
        cout << "No." << count_i + 1 << ":" << aaa[count_i] << endl;
    return 0;
}

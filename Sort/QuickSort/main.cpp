/*
*   This is implementation for QuickSort
*   Wrote by Cong
*   2018.2.28
*/

#include "iostream"

#define datatype int

#define big    1
#define equal  2
#define small  3


using namespace std;

class QuickSort
{
public:
    void sort(datatype *dataset, int low, int high);
    void sort(datatype *dataset, int length);
    void show(datatype *dataset, int length);
private:
    void exchange(datatype *dataset, int pos1, int pos2);
    int  compare(datatype data1, datatype data2);
};

void QuickSort::exchange(datatype *dataset, int pos1, int pos2)
{
    datatype temp = dataset[pos1];
    dataset[pos1] = dataset[pos2];
    dataset[pos2] = temp;
}

int QuickSort::compare(datatype data1, datatype data2)
{
    if(data1 > data2)
        return big;
    else if(data1 < data2)
        return small;
    else
        return equal;
}

void QuickSort::show(datatype *dataset, int length)
{
    for(int i = 0; i < length; i += 1)
        cout << dataset[i] << endl;
}

void QuickSort::sort(datatype *dataset, int low, int high)
{
    //randomize the data
    //blabla
    if(low >= high) return;         //STOP
    int lo = low + 1, hi = high;
    int target = dataset[low];
    int count_i = lo, count_j = hi;

    while(true)
    {
        for(;compare(dataset[count_i], target) != big  ; count_i += 1)
            if(count_i == hi)   break;
        for(;compare(dataset[count_j], target) != small; count_j -= 1)
            if(count_j == lo)   break;
        if(count_i >= count_j) break;
        exchange(dataset, count_i, count_j);
    }
    exchange(dataset, low, count_j);

    sort(dataset, low, count_j - 1);
    sort(dataset, count_j + 1, hi);
}

void QuickSort::sort(datatype *dataset, int length)
{
    sort(dataset, 0, length - 1);
}

int main()
{
    datatype arr[6] = {2,4,5,1,1,7};
    QuickSort a;
    a.sort(arr,6);
    a.show(arr,6);
    return 0;
}



#include "iostream"

#define datatype int

#define big    1
#define equal  2
#define small  3

using namespace std;

class ShellSort
{
public:
    void sort(datatype *dataset, int length);
    void show(datatype *dataset, int length);
private:
    void exchange(datatype *dataset, int pos1, int pos2);
    int  compare(datatype *dataset, int pos1, int pos2);
};

void ShellSort::exchange(datatype *dataset, int pos1, int pos2)
{
    datatype temp = dataset[pos1];
    dataset[pos1] = dataset[pos2];
    dataset[pos2] = temp;
}

int ShellSort::compare(datatype *dataset, int pos1, int pos2)
{
    if(dataset[pos1] > dataset[pos2])
        return big;
    else if(dataset[pos1] < dataset[pos2])
        return small;
    else
        return equal;
}

void ShellSort::show(datatype *dataset, int length)
{
    for(int i = 0; i < length; i += 1)
        cout << dataset[i] << endl;
}

void ShellSort::sort(datatype *dataset, int length)
{
    if(length <= 1)
        return;
    int step = 0;
    int count = 0;
    while((3 * step) < length - 1)    step = step * 3 + 1;

    while(step >= 1)
    {
//I'm not sure which one is more effective, but they work
/*********1**********/
        for(count = step; count < length; count += 1)
        {
            for(int count_i = count; count_i > 0 && compare(dataset, count_i, count_i - step) == small; count_i -= step)
                exchange(dataset, count_i, count_i - step);
        }

/*
*********2**********
        for(count = 0; count < step; count += 1)
        {
            for(int count_i = count; count_i < length; count_i += step)
            {
                for(int count_j = count_i; count_j + step < length && count_j >= 0 
                    && compare(dataset, count_j + step, count_j) == small; count_j -= step)
                    exchange(dataset, count_j + step, count_j);
            }
        }
*/
        step = (step - 1) / 3;
    }

}



int main()
{
    datatype arr[6] = {4,2,5,1,3,7};
    ShellSort a;
    a.sort(arr,6);
//    cout << arr[0] << endl;
    a.show(arr,6);
    return 0;
}


/*
*   This uses heap to implement Heap Sort
*   Wrote by Cong
*   2018.3.8
*/


#include "iostream"

#define datatype int

#define big    1
#define equal  2
#define small  3


using namespace std;


class Heap
{
public:
    Heap();
    Heap(int size);
    void exchange(datatype *dataset, int pos1, int pos2);
    int  compare (datatype *dataset, int pos1, int pos2);
    void swim(int p);
    void sink(int p, int num);    //num is the range of sink
    void insert(datatype data);
    void change(datatype data, int p);
    datatype delmax();
    void sort();
    void show();
    ~Heap();
private:
    datatype *dataset;
    int num;
    int size;
};

Heap::Heap()
{
    size = 10;
    num = 0;
    dataset = new datatype[size + 1];
}
Heap::Heap(int size)
{
    this->size = size;
    num = 0;
    dataset = new datatype[size + 1];
}

void Heap::exchange(datatype *dataset, int pos1, int pos2)
{
    datatype temp = dataset[pos1];
    dataset[pos1] = dataset[pos2];
    dataset[pos2] = temp;
}

int Heap::compare(datatype *dataset, int pos1, int pos2)
{
    if(dataset[pos1] > dataset[pos2])
        return big;
    else if(dataset[pos1] < dataset[pos2])
        return small;
    else
        return equal;
}

void Heap::swim(int p)
{
    if(p < 2)
        return;
    if(compare(dataset, p / 2, p) != small)
        return;
    exchange(dataset, p / 2, p);
    swim(p / 2);
}

//For example, sink(3,8) means that sink the pos 3 in a heap which contain 8 elements
void Heap::sink(int p, int num)
{
    if(num > this->num)
        return;
/*
    if(2 * p > num)
        return;
    if(2 * p + 1 > num)
    {
        //in this case, the left(2p) node is in the heap, but the right(2p+1) node is not in the heap
        if(compare(dataset, p, 2 * p) != big)
            exchange(dataset, p, 2 * p);
        return;
    }
    //the left and right nodes are in the heap
    if(compare(dataset, p, 2 * p) != small && compare(dataset, p, 2 * p + 1) != small )
        return;
    if(compare(dataset, 2 * p, 2 * p + 1) == big)
    {
        exchange(dataset, 2 * p, p);
        sink(2 * p);
    }
    else
    {
        exchange(dataset, 2 * p + 1, p);
        sink(2 * p + 1);
    }
*/
    //another way to implement sink
    if(2 * p > num)
        return;
    int j = 2 * p;
    if(j < num && compare(dataset, j, j + 1) == small)  j = j + 1;
    if(compare(dataset, p, j) != small)                 return;
    exchange(dataset, p, j);
    sink(j, num);
}

void Heap::insert(datatype data)
{
    if(num + 1 > size)  //this mean the heap is full

        return;         //resize the heap
    dataset[num + 1] = data;
    //to keep heap orderly
    swim(num + 1);
    num += 1;
}

void Heap::change(datatype data, int p)
{
    if(p > num)
        return;
    dataset[p] = data;
    sink(p, num);
    swim(p);
}

datatype Heap::delmax()
{
    datatype data = dataset[num];
    exchange(dataset, 1, num);
    num -= 1;
    sink(1, num);
    return data;
}

void Heap::sort()
{
    int temp = num;
    while(temp > 1)
    {   
        exchange(dataset, 1, temp);
        temp -= 1;
        sink(1,temp);
    }
}

void Heap::show()
{
    for(int i = 1; i < num + 1; i += 1)
    {
        cout << dataset[i] <<endl;
    }
}

Heap::~Heap()
{
    delete dataset;
}

int main()
{
    cout << "hello world" << endl;
    Heap a;
    for(int i = 0; i < 7; i += 1)
        a.insert(i);
    a.show();
    cout << "change the num at position 4 to 9"<< endl;
    a.change(9,4);
    a.show();
    cout << "change the num at position 1 to 2" << endl;
    a.change(2,1);
    a.show();
    cout << "delete the max num of the heap" << endl;
    a.delmax();
    a.show();
    cout << "Heap Sort" << endl;
    a.sort();
    a.show();
    return 0;
}

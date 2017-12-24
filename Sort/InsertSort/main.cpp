/*
*   This is implementation for InsertSort which use linked list
*   Wrote by Cong
*   2017.12
*/

#include"iostream"
#include "linked_list.h"

using namespace std;

int main()
{
/*******the following codes are used for testing linked_list***************/
    int temp;
    linked_list<int> a;
    //add
    cout << "add 10 element" << endl;
    for (int i = 0; i < 10; i += 1)
        a.add(i);
    cout << "add 5 to pos 5" << endl;
    temp = 5;
    a.add(5, temp);
    //show
    a.show_all();
    //change
    cout << "change the element which is at pos 11 to 3 " << endl;    
    node<int>* b;
    temp = 3;
    b = a.change(11, temp);
    cout << endl;
    if(b != NULL)
    {
        cout << b->front->data << endl;
        cout << b->data << endl;
        cout << b->rear->data  << endl;
    }
    cout << endl;

    a.show_all();

    //remove
    cout << "remove" << endl;
    a.remove();
    a.show_all();
    cout << endl;

    cout << "remove pos 3" <<endl;
    temp = 3;
    a.remove(temp);
    a.show_all();
    cout << endl;
    
    //exchange
    cout << "exchange 1 and 7" << endl;
    a.exchange(1, 7);
    a.show_all();
    cout << endl;

    //find
    cout << "find 5 in 1-5" << endl;
    temp = 5;
    int c = 0;
    c = a.find(1, 5, temp);
    cout << endl;
    cout << c << endl;
    cout << endl;

    //show data at specified pos
    cout << "show data at pos 6" << endl;
    b = a.show_data(6);
    cout << endl;
    if(b != NULL)
    {
        cout << b->front->data << endl;
        cout << b->data << endl;
        cout << b->rear->data  << endl;
    }
    cout << endl;
    
    int size_temp = a.show_size();
    cout << "size:" << size_temp << endl;
    cout << "hello world" << endl;
    return 0;
}

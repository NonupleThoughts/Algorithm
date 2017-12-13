#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

//the implementation of the function of linked_list is all in this file
//this is because that "Templates can only be implemented in the header file"


#include "iostream"

using std::cout;
using std::endl;

//i think that the node is no need to set as a class
//because node is very simple, and it just put one memory which is used to save data and two pointers into a block
template <class datatype>
struct node
{
    datatype  data;
    node     *front;
    node     *rear;
    
};

template <class datatype>
class linked_list
{
public:    
    linked_list();
    linked_list(datatype data);

    void show_info();
    
    ~linked_list();

protected:
    node<datatype> head;
    int  size;

private:

};

template <class datatype>
inline linked_list<datatype>::linked_list()
{
    head.data = (datatype)0;
    head.front = NULL;
    head.rear  = NULL;
    size = 0;
}

template <class datatype>
inline linked_list<datatype>::linked_list(datatype data)
{
    head.data = data;
    head.front = NULL;
    head.rear  = NULL;
    size = 1;
}

template <class datatype>
inline void linked_list<datatype>::show_info()
{
    cout << "data"  << head.data  << '\n'
         << "front" << head.front << '\n'
         << "rear"  << head.rear  << '\n'
         << "size"  << size       << endl;
}


template <class datatype>
inline linked_list<datatype>::~linked_list()
{

}

#endif  //_LINKED_LIST_H_

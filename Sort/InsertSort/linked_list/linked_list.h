/*
*   The head file of linked list
*   Wrote by Cong
*   2017.12.24
*/


#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

//the implementation of the function of linked_list is all in this file
//this is because that "Templates can only be implemented in the header file"


#include "iostream"
#define SUCCESS   0
#define FAIL      1
#define EMPTY     0
#define NOT_EMPTY 1


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
    int             add(datatype &data);
    int             add(int pos, datatype &data);
    node<datatype>* change(datatype &data);
    node<datatype>* change(int pos, datatype &data);
    node<datatype>* remove();
    node<datatype>* remove(int pos);
    int             exchange(int pos1, int pos2);
    int             find(int start, int end, datatype &data);
    node<datatype>* show_data(int pos);
    int             show_size();
    void            show_all();
    void            insertsort();
    void            reset();
    ~linked_list();

protected:
    node<datatype>  head;
    node<datatype>  tail;
    node<datatype> *current;
    node<datatype>  data_raw; //this variable is a return value of some functions
    int  size;

private:

};

template <class datatype>
inline linked_list<datatype>::linked_list()
{
    head.data  = (datatype)0;
    head.front = NULL;
    head.rear  = &tail;

    tail.data  = (datatype)0;
    tail.front = &head;
    tail.rear  = NULL;

    current    = &head;

    data_raw.data  = (datatype)0;
    data_raw.front = NULL;
    data_raw.rear  = NULL;

    size = 0;
}

//by default, add new data to the end of linked list
template <class datatype>
int linked_list<datatype>::add(datatype &data)
{
    node<datatype> *cache = new node<datatype>;
    if(cache == NULL)
        return FAIL;

    cache->data  = data;    
    cache->front = current;
    cache->rear  = &tail;

    current->rear = cache;

    current = cache;

    size += 1;

    return SUCCESS;
}


//add data to the specified postion
template <class datatype>
int linked_list<datatype>::add(int pos, datatype &data)
{
    if(pos > size || pos <= 0)
        return FAIL;

    node<datatype> *cache = new node<datatype>;
    if(cache == NULL)
        return FAIL;

    //in this way "temp" will point to the position which before the specified position
    node<datatype> *temp = &head;
    for(int count_i = 0; count_i < pos - 1; count_i += 1)
        temp = temp->rear;
    
    cache->data  = data;
    cache->front = temp;
    cache->rear  = temp->rear;
    
    temp->rear   = cache; 
    

    size += 1;

    return SUCCESS;
}

//by default, change the data which is at the end of linked list
template <class datatype>
node<datatype>* linked_list<datatype>::change(datatype &data)
{
    data_raw.data  = current->data;
    data_raw.front = current->front;
    data_raw.rear  = current->rear;

    current->data  = data;

    return &data_raw;
}

//change the data which is at the specified postion
template <class datatype>
node<datatype>* linked_list<datatype>::change(int pos, datatype &data)
{
    if(pos > size || pos <= 0)
        return NULL;
 
    //find the specified position
    node<datatype> *temp = &head;
    for(int count_i = 0; count_i < pos; count_i += 1)
        temp = temp->rear;

    data_raw.data  = temp->data;
    data_raw.front = temp->front;
    data_raw.rear  = temp->rear;

    temp->data = data;

    return &data_raw;
}

//by default, remove the data which is at the end of linked list
template <class datatype>
node<datatype>* linked_list<datatype>::remove()
{
    node<datatype> *cache;
    cache = current;

    current = cache->front;
    current->rear = cache->rear;
    cache->rear->front = current;


    data_raw.data  = cache->data;
    data_raw.front = cache->front;
    data_raw.rear  = cache->rear;

    size -= 1;

    delete cache;

    return &data_raw;
}

//remove the data which is at the specified postion
template <class datatype>
node<datatype>* linked_list<datatype>::remove(int pos)
{
    if(pos > size || pos <= 0)
        return NULL;

    node<datatype> *cache;

    //in this way "temp" will point to the position which before the specified position
    node<datatype> *temp = &head;
    for(int count_i = 0; count_i < pos - 1; count_i += 1)
        temp = temp->rear;

    cache = temp->rear;
    temp->rear = cache->rear;
    cache->rear->front = temp;

    data_raw.data  = cache->data;
    data_raw.front = cache->front;
    data_raw.rear  = cache->rear;

    size -= 1;

    delete cache;

    return &data_raw;
}

template <class datatype>
int linked_list<datatype>::exchange(int pos1, int pos2)
{
    if(pos1 > size || pos1 <= 0)
        return FAIL;
    if(pos2 > size || pos2 <= 0)
        return FAIL;

    datatype data_cache;

    node<datatype> *temp1 = &head;      //point to the data which is at pos1
    node<datatype> *temp2 = &head;      //point to the data which is at pos2

    //the two loops will repeat (pos1 + pos2) times
    //those could be improved, and will repeat max(pos1, pos2) times
    //if i have time i will implement it
    for(int count_i = 0; count_i < pos1; count_i += 1)
        temp1 = temp1->rear;
    for(int count_i = 0; count_i < pos2; count_i += 1)
        temp2 = temp2->rear;

    //exchange data
    data_cache  = temp1->data;
    temp1->data = temp2->data;
    temp2->data = data_cache;
    
    return SUCCESS;
}

//this function will return the first element which is equal to "data"
//there may be some improved methods to solve this problem but i have not found it
//beside there could use dichotomy to improve the efficiency of find
template <class datatype>
int linked_list<datatype>::find(int start, int end, datatype &data)
{
    if(start > size || start <= 0)
        return FAIL;
    if(end > size || end <= 0)
        return FAIL;
    if(start > end)
        return FAIL;

    //find the specified position
    node<datatype> *temp = &head;
    int pos = 0;
    while(pos < end)
    {
        temp = temp->rear;
        pos += 1;
        if(pos >= start)
        {
            if(temp->data == data)
                break;
            else 
                if(pos == end)
                    return FAIL;        //there is not element which is equal to "data" in the specified range
        }
    }
    
    return pos;
}

//return the pointer of an element which is at specified postion
template <class datatype>
node<datatype>* linked_list<datatype>::show_data(int pos)
{
    if(pos > size || pos <= 0)
        return NULL;

    //find the specified position
    node<datatype> *temp = &head;
    for(int count_i = 0; count_i < pos; count_i += 1)
        temp = temp->rear;

    data_raw.data  = temp->data;
    data_raw.front = temp->front;
    data_raw.rear  = temp->rear;

    return &data_raw;
}

template <class datatype>
inline int linked_list<datatype>::show_size()
{
    return size;
}

template <class datatype>
void linked_list<datatype>::show_all()
{
    node<datatype> *temp = &head;
    for(int count_i = 0; count_i < size; count_i += 1)
    {
        temp = temp->rear;
        cout << "No." << count_i + 1  << ":" << temp->data << endl;
    }
    cout << "size:"  << size << endl;
/*
    cout << "data"  << head.data  << '\n'
         << "front" << head.front << '\n'
         << "rear"  << head.rear  << '\n'
         << "size"  << size       << endl;
*/
}

//by default the data will be arranged from small to large
template <class datatype>
void linked_list<datatype>::insertsort()
{
    int count_i = 0;
    int count_sort = 0;
    node<datatype> *sort_pos = head.rear;
    node<datatype> *temp     = head.rear;     //"temp" always points to the first element
    node<datatype> cache;
    for(count_sort = 1; count_sort <= size; count_sort += 1)
    {
        for(count_i = 1; count_i < count_sort; count_i += 1)
        {
            if(sort_pos->data < temp->data)
            {
                //move sort_pos to the postion before temp
                sort_pos->front->rear = sort_pos->rear;
                sort_pos->rear->front = sort_pos->front;

                sort_pos->rear  = temp;
                sort_pos->front = temp->front;
 
                temp->front->rear = sort_pos;
                temp->front = sort_pos;

                break;
            }
            temp = temp->rear;
        }

        sort_pos = sort_pos->rear;
        temp     = head.rear;
    }
}

//in this function all the element in linked list will be delete
//and all codes in this function are the same as the codes in destructor
template <class datatype>
void linked_list<datatype>::reset()
{
    //when free the memory,
    //there may need a pointer to save the address of next memory which is contained by the current memory,
    //so there need two temp pointer.
    node<datatype> *temp1 = head.rear;        //point to the current memory
    node<datatype> *temp2 = temp1->rear;      //point to the next memory
    for(int count_i = 0; count_i < size; count_i += 1)
    {
        delete temp1;
        temp1 = temp2;
        temp2 = temp1->rear;
    }
    size = 0;
}

template <class datatype>
inline linked_list<datatype>::~linked_list()
{
    //when free the memory,
    //there may need a pointer to save the address of next memory which is contained by the current memory,
    //so there need two temp pointer.
    node<datatype> *temp1 = head.rear;        //point to the current memory
    node<datatype> *temp2 = temp1->rear;      //point to the next memory
    for(int count_i = 0; count_i < size; count_i += 1)
    {
        delete temp1;
        temp1 = temp2;
        temp2 = temp1->rear;
    }
    size = 0;
}

#endif  //_LINKED_LIST_H_

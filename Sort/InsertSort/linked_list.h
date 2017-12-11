#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

class UF
{
public:
    UF(int n);                                  //initialize N nodes with integer group (0 to N - 1)
    int  UFfind(int p);                         //return the group of p (0 to N - 1)
    void UFset(int p, int group);               //set the group of node p
    bool UFconnected(int p, int q);             //return true if p and q are in the same group
    void UFunion(int p, int q);                 //add connection between p and q
    void UFdetail();                            //print the group of the node
    ~UF();                                      //free memory

private:
    ;
    int num;                                    //the number of node
};

#endif  //_LINKED_LIST_H_

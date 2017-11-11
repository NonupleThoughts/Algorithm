#include <iostream>

#define def_num 10

using namespace std;


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
    int *id;
    int num;                                    //the number of node
};

UF::UF(int n = def_num)
{
    id = new int[n];
    int count_i = 0;
    for(count_i = 0; count_i < n; count_i += 1)
        id[count_i] = count_i;                   //the element contained in the array p is the group of node
    num = n;
    cout << "hello world" <<endl;
}

int UF::UFfind(int p)
{
    return id[p];
}

void UF::UFset(int p, int group)
{
    id[p] = group;
}

bool UF::UFconnected(int p, int q)
{
    return UFfind(p) == UFfind(q);
}

void UF::UFunion(int p, int q)
{
    if(UFconnected(p, q) == false)
    {
        int pid = UFfind(p);
        int qid = UFfind(q);
        for(int i = 0; i < num; i += 1)
            if(UFfind(i) == pid)
                UFset(i,qid);
    }

}

void UF::UFdetail()
{
    for(int i = 0; i < num; i += 1)
    {

        cout << "node" << i << '\t';
        cout << "group" << id[i] << endl;
    }
}

UF::~UF()
{
    delete []id;
    cout << "goodbye" <<endl;
}


int main()
{
    UF a;
    a.UFunion(1,2);
    a.UFunion(1,5);
    a.UFunion(7,9);
    a.UFdetail();
    return 0;
}

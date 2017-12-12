#include <iostream>
#include <string>

using namespace std;

template <class T1>
class person
{
    protected:
        T1 name;
    public:
        void set_name(T1 new_name);
        void show_info(){ cout << "name" << name << endl; }

};

template <class T1>
void person<T1>::set_name(T1 new_name)
{ name = new_name; }


template <class T1>
class teacher:public person<T1>
{
    protected:
        T1 id;
    public:
        teacher(T1 p_id){ id = p_id; }
        void set_id(T1 p_id);
        //note one: if the next line is commented
        //void set_name(T1 name){ person<T1>::set_name(name);}

        //in the define of subclass we could use person<T1> to access to the member of base class
        void show_info(){ cout << "name:" << person<T1>::name << '\n' << "teacher id:" << id << endl;}
};

template <class T1>
void teacher<T1>::set_id(T1 p_id)
{ id = p_id; }


int main()
{
    teacher<string> a("dsadas");
    //note one: this code will pass. 
    //In this situation(there is a object of the subclass),
    //i think, if the subclass doesn't have the same name function with base class,
    //the subclass could find this function in the base class
    a.set_name("name");
    a.show_info();
    return 0;
}

#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>

//using namespace std;

using std::string;
using std::cout;
using std::endl;

class person
{
    protected:
        string name;
        int age;
        int phone;
    public:
        person();
        person(string p_name, int p_age, int phone_num);
        void set_name(string new_name);
        void set_age(int new_age);
        void set_phone(int new_num);
        void show_info();
        ~person();

};


inline person::person()
{
    name  = "NULL";
    age   = 0;
    phone = 1234;
}


inline person::person(string p_name, int p_age, int phone_num)
{
    name  = p_name;
    age   = p_age;
    phone = phone_num;
}

inline void person::set_name(string new_name)
{
    name = new_name;
}


inline void person::set_age(int new_age)
{
    age = new_age;
}

inline void person::set_phone(int new_num)
{
    phone = new_num;
}

inline void person::show_info()
{

    cout << "name:" << name <<endl;
    cout << "age:"  << age <<endl;
    cout << "phone number:" << phone <<endl;
}

inline person::~person()
{
    ;
}


class teacher:public person
{
    protected:
        string id;
    public:
        teacher(string p_name, int p_age, int phone_num, string p_id);
        void show_info();
        ~teacher();
};

inline teacher::teacher(string p_name, int p_age, int phone_num, string p_id):person(p_name, p_age, phone_num)
{
    id = p_id;
    cout << "teacher " << p_name << " is create" << endl;
}

inline void teacher::show_info()
{
    cout << "name:" << name <<endl;
    cout << "age:"  << age <<endl;
    cout << "phone number:" << phone <<endl;
    cout << "teacher id:" << id << endl;
}

inline teacher::~teacher()
{
    cout << "teacher " << name << " is delete" << endl;
}
#endif //_PERSON_H_

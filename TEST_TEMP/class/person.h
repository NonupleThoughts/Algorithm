#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>

using namespace std;

class person
{
    private:
        string name;
        int age;
        int phone_num;
    public:
        person();
        person(string p_name, int p_age, int phone);
        void set_name(string new_name);
        void set_age(int new_age);
        void set_phone(int new_num);
        void show_info();
        ~person();

};

inline person::person()
{
    name      = "NULL";
    age       = 0;
    phone_num = 1234;
}


inline person::person(string p_name, int p_age, int phone)
{
    name      = p_name;
    age       = p_age;
    phone_num = phone_num;
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
    phone_num = new_num;
}

inline void person::show_info()
{

    cout << "name:" << name <<endl;
    cout << "age:"  << age <<endl;
    cout << "phone number:" << phone_num <<endl;
}

inline person::~person()
{
    ;
}




#endif //_PERSON_H_

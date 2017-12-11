/*  This is test file for inheritance of class
*   Wrote by Cong
*   2017.12.11
*/


#include "iostream"
#include "string"
#include "person.h"

using namespace std;

int main()
{
//    string a = "helloworld";
//    cout << a << endl;
    person a;
    a.set_name("wang er");
    a.set_age(18);
    a.set_phone(1123);
    a.show_info();
    return 0;
}


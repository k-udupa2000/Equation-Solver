#include "Task_1.h"

Task_1 :: Task_1(const Task_1& t) 
{
    _a=t._a;
    _b=t._b;
    _c=t._c;
}

Task_1 :: Task_1(float a,float b,float c)
{
    _a=a;
    _b=b;
    _c=c;
}

Task_1 :: ~Task_1() 
{
    cout << "Task_1 destructor called" << endl ;
}

string Task_1 :: calc_Task_1()
{
    float x=(_c - _b)/_a;
    char a='"';
    string b (1,a);
    string res=b+"x="+to_string(x)+b;
    return res;
}
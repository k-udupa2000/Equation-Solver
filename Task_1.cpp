#include "Task_1.h"

Task_1 :: Task_1(const Task_1& t) 
{
    _a=t._a;
    _b=t._b;
    _c=t._c;
}

Task_1 :: Task_1(double a,double b,double c)
{
    _a=a;
    _b=b;
    _c=c;
}

Task_1 :: ~Task_1() 
{
    cout << "Task_1 destructor called" << endl ;
}

double Task_1 :: calc_Task_1()
{
    if(_a != 0)
    {
        double x=(_c - _b)/_a;
        return x;
    }
    else
    {
        cout<<"Error: Division by zero";
        return -1;
    }
}
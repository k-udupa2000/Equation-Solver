#include "Task1.h"

Task1 :: Task1(const Task1& t) 
{
    _a=t._a;
    _b=t._b;
    _c=t._c;
}

Task1 :: Task1(double a,double b,double c)
{
    _a=a;
    _b=b;
    _c=c;
}

Task1 :: ~Task1() 
{}

double Task1 :: solve()
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
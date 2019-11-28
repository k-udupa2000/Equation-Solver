#include "Task1.h"

Task1 ::Task1(const Task1 &t)
{
    _a = t._a;
    _b = t._b;
    _c = t._c;
}

Task1 ::Task1(double a, double b, double c)
{
    _a = a;
    _b = b;
    _c = c;
}

Task1 ::~Task1()
{
}

double Task1 ::solve()
{
    if (_a != 0)
    {
        x = (_c - _b) / _a;
        flag = 1;
        if(x == -0)
            x = 0;
        
        return x;
    }
    flag = 0;
    return -1;
}
void Task1 ::print()
{
    cout << *this << endl;
}
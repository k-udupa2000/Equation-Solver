#ifndef _Task_1_h_
#define _Task_1_h_
#include<iostream>
#include<string>
using namespace std;

//equation _ax + _b= _c;
class Task_1
{
    
    double _a,_b,_c;
    public:
    Task_1(const Task_1 &t);
    Task_1(double a,double b,double c);
    ~Task_1();

    double calc_Task_1();
    friend ostream &operator<<(ostream &out, Task_1 &dt)
    {
        char a='"';
        out << a << "x=" << dt.calc_Task_1() << a << "\t";
        return out;
    }

};
/*
errors :
1)_a=0 (division by zero error)
*/
#endif
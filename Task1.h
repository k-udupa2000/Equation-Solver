#pragma once
#include<iostream>
#include<string>
using namespace std;

//equation _ax + _b= _c;
class Task1
{
    
    double _a,_b,_c;
    public:
    Task1(const Task1 &t);
    Task1(double a,double b,double c);
    ~Task1();

    double solve();
    public :
    friend ostream &operator<<(ostream &out, Task1 &dt);
    friend ostream &operator<<(ostream &out, Task1 &dt)
    {
        char a='"';
        out << a << "x=" << dt.solve() << a << "\t";
        return out;
    }

};
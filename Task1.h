#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Solver.h"
using namespace std;

//equation _ax + _b= _c;
class Task1 : public Solver
{

    double _a, _b, _c;

public:
    Task1(const Task1 &t);
    Task1(double a, double b, double c);
    ~Task1();
    void print();

    double solve();

public:
    friend ostream &operator<<(ostream &out, Task1 &dt);
    friend ostream &operator<<(ostream &out, Task1 &dt)
    {
        char a = '"';
        float x = dt.solve();
        if (x != 0)
            out << setprecision(4) << a << "x=" << dt.solve() << a << "\t";
        return out;
    }
};
#pragma once

#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstdlib>

#include "Task4.h"
#include "Solver.h"
using namespace std;
class Task4 : public Solver
{
public:
    Task4();
    Task4(string s);
    double geta();
    double getb();
    double getc();
    void parse(string str);
    vector<double> solve();
    int find_d(double, double, double);
    friend ostream &operator<<(ostream &out, Task4 &c);
    void print();

private:
    double a, b, c;
    string str;
};
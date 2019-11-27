#pragma once
#include"Solver.h"
#include"Base_Task2.h"
class Task2 : public Base, public Solver
{
    int flag=0;
    public:
        Task2(string e1, string e2);
        void solve();
        void get_val_eq1();
        void get_val_eq2();
        void print();
        friend ostream &operator <<(ostream &output, Task2 th);

};


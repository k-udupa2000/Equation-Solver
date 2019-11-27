#pragma once

#include <iomanip>

#include"Solver.h"
#include"Base_Task7.h"
class Task7: public Base_Task7, public Solver
{
    float a,b,c,d,e,f,sol;
    public:

    Task7(string input);
    void solveexpo();
    void print();
    friend ostream& operator <<(ostream& output,Task7 obj);
    float geta();
    float getd();
    float getsol();
    
    
    


};

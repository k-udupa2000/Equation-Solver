#ifndef _Task_1_h_
#define _Task_1_h_
#include<iostream>
#include<string>
using namespace std;

//equation _ax + _b= _c;
class Task_1
{
    float _a,_b,_c;
    public:
    Task_1(const Task_1 &t);
    Task_1(float a,float b,float c);
    ~Task_1();

    string calc_Task_1();

};
/*
errors :
1)_a=0 (division by zero error)
*/
#endif
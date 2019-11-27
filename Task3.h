#pragma once

#include"Task1.h"
class Task3 : public Task1
{
    // ax +/- b = cx +/- d
    //double a, b, c, d;
    public :
        Task3(double a, double b, double c, double d) : Task1(a - c, b, d)
    {}
};
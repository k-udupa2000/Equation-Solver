#include"Task_1.h"
class Task3 : public Task_1
{
    // ax +/- b = cx +/- d
    //double a, b, c, d;
    public :
        Task3(double a, double b, double c, double d) : Task_1(a - c, b, d)
    {}
};
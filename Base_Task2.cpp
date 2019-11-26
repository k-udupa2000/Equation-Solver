#include"Base_Task2.h"

Base::Base(string e1, string e2):e1(e1) , e2(e2)
{}
void Base::set_a1(double n)
{
    x_cofs.first=n;
}

void Base::set_a2(double n)
{
    x_cofs.second=n;
}

void Base::set_b1(double a)
{
    y_cofs.first=a;
}

void Base::set_b2(double a)
{
    y_cofs.second=a;
}

void Base::set_c1(double a)
{
    c.first=a;
}

void Base::set_c2(double a)
{
    c.second=a;
}

void Base::set_x(double a)
{
    x_y.first=a;
}

void Base::set_y(double a)
{
    x_y.second=a;
}

double Base::get_a1()
{
    return x_cofs.first;
}

double Base::get_a2()
{
    return x_cofs.second;
}

double Base::get_b1()
{
    return y_cofs.first;
}

double Base::get_b2()
{
    return y_cofs.second;
}

double Base::get_c1()
{
    return c.first;
}

double Base::get_c2()
{
    return c.second;
}

double Base::get_x()
{
    return x_y.first;
}

double Base::get_y()
{
    return x_y.second;
}

string Base::get_e1()
{
    return e1;
}

string Base::get_e2()
{
    return e2;
}
void Base::set_opr(string s)
{
    opr=s;
}

string Base::get_opr()
{
    return opr;
}

void Base::print()
{
    if((isinf(x_y.first) && isinf(x_y.second)) ||(isnanf(x_y.first) && isnanf(x_y.second)))
    {
        cout << "No REAL solution for the given equation" << endl;
    }
    cout << "x=" <<setprecision(4) << x_y.first <<";" <<"y="<<setprecision(4)<<x_y.second<<endl;
}

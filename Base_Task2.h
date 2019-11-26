#ifndef BASE_H
#define BASE_H
#include<bits/stdc++.h>
#include<utility>
#include<string>

using namespace std;

class Base
{ 
    pair <double, double> x_cofs;
    pair <double, double> y_cofs;
    pair <double, double> c;
    pair <double, double> x_y;
    string opr;
    string e1, e2;
    public:
        Base(string e1,string e2);
        virtual void solve()=0;
        void set_a1(double n);
        void set_a2(double n);
        void set_b1(double n);
        void set_b2(double n);
        void set_c1(double n);
        void set_c2(double n);
        void set_x(double n);
        void set_y(double n);
        void set_opr(string s);
        double get_a1();
        double get_a2();
        double get_b1();
        double get_b2();
        double get_c1();
        double get_c2();
        double get_x();
        double get_y();
        string get_opr();
        string get_e1();
        string get_e2();
        void print();
};
#endif
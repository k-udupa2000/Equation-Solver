#pragma once
#include <cmath>
#include<iostream>
#include<vector>
using namespace std;
class task4 
{
public:
    task4();
    task4(string s);
    double geta();
    double getb();
    double getc();
    void parse(string str);
    //double plus ();
    //double minus (); 
    vector<double> solve();
    int find_d (double, double ,double);
private:
    double a,b,c;
    string str;
};
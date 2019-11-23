/*
    @author: Shubhayu Das
    *  ax+b=c is            type 1
    *  ax+by=c;dx+ey=f is   type 2
    *  ax+b=cx+d is         type 3
    *  ax^2+bx+c=d is       type 4
    *  a^(bx+c)=d^(ex+f) is type 7
    *  |ax+b|=cx+d is       type 9
*/

#pragma once

#include <string>
#include <vector>
#include <utility>
#include <iterator>
#include <sstream>
#include <iostream>

using namespace std;

class REPL
{
public:
    REPL();
    REPL(string);
    REPL(const REPL &);
    ~REPL();

    void detectType();
    int getType() const;
    void setCoeff(vector<pair<string, string>>);
    vector<pair<string, string>> getCoeff() const;

private:
    void split(string &inp, char delimiter, vector<string> &parts)
    {
        stringstream ss(inp);
        string item;
        while (getline(ss, item, delimiter))
            parts.push_back(item);
    }

    int isValidOneVariable(pair<string, string> inp, string var)
    {
        size_t first = inp.first.find(var), second = inp.second.find(var);

        if (first != string::npos && second != string::npos)
            return 1;
        else if (first != string::npos || second != string::npos)
            return 2;

        return 0;
    }

    int isValidTwoVariable(vector<pair<string, string>> inp, string var1, string var2)
    {
        size_t first_L_X = inp[0].first.find(var1), first_L_Y = inp[0].first.find(var2);
        size_t first_R_X = inp[0].second.find(var1), first_R_Y = inp[0].second.find(var2);

        bool first = (first_L_X != string::npos && first_L_Y != string::npos) || (first_R_X != string::npos && first_R_Y != string::npos);

        if(!first)
            return -1;

        size_t second_L_X = inp[1].first.find(var1), second_L_Y = inp[1].first.find(var2);
        size_t second_R_X = inp[1].second.find(var1), second_R_Y = inp[1].second.find(var2);

        bool second = (second_L_X != string::npos && second_L_Y != string::npos) || (second_R_X != string::npos && second_R_Y != string::npos);

        if(!second)
            return -1;

        return 2;
    }

    short _type;    //  Stores the type of the equation
    vector<pair<string,string>> _coefficients;      // stores the LHS and RHS
    string _input;  //  This is given by the user
};

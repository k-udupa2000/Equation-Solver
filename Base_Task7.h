#ifndef _Base_Task7_h_
#define _Base_Task7_h_
#include<bits/stdc++.h>
using namespace std;

class Base_Task7{

string eq;	
	
public:

	Base_Task7(string input);
    vector<string> formbx(string input);
    vector<string> formbxplusc(string input);
    vector<string> formcplusbx(string input);
    vector<string> formc(string input);
    vector<string> getcoeff(string input1);
    virtual void solveexpo()=0;
    string geteq();



};
#endif
#ifndef _Task_7_h_
#define _Task_7_h_
#include<bits/stdc++.h>
using namespace std;
#include"Task_1.h"
class Task_7:public Task_1{
	
	
public:
	Task_7(float A,float B,float C,float D,float E,float F):Task_1(log(A)*B-log(D)*E,log(A)*C,log(D)*F){}
	string solveexpo();



};
#endif
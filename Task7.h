#pragma once
#include<bits/stdc++.h>
using namespace std;
#include"Task1.h"
class Task_7:public Task1{
	
	
public:
	Task_7(float A,float B,float C,float D,float E,float F):Task1(log(A)*B-log(D)*E,log(A)*C,log(D)*F){}
	string solveexpo();



};
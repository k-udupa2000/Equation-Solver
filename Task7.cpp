#include"Task7.h"
Task_7::Task_7(float A,float B,float C,float D,float E,float F)
{
	a=A;
	b=B;
	c=C;
	d=D;
	e=E;
	f=F;
}
float Task_7::solveexpo()
{
	float t=b*log(a)-e*log(d);
	float g=f*log(d)-c*log(a);
	float l;
	if(t!=0)
		l=g/t;
	else
		l=numeric_limits<float>::max();
		
	
		
	return l;
}

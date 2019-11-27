#include"Task7.h"
Task7::Task7(string input):Base_Task7(input){}
void Task7::solveexpo()
{
    vector<string> tp=this->getcoeff(this->geteq());
    a=stof(tp[0]);
    b=stof(tp[1]);
    c=stof(tp[2]);
    d=stof(tp[3]);
    e=stof(tp[4]);
    f=stof(tp[5]);
    float t=b*log(a)-e*log(d);
	float g=f*log(d)-c*log(a);
	
	if(t!=0)
		sol=g/t;
	else
		sol=numeric_limits<float>::max();
    
			
	
}
void Task7::printsoln()
{
    if(a>0 && d>0)
    {
            if(sol!=numeric_limits<float>::max())
                cout<<"x="<<fixed<<setprecision(4)<<sol<<'\n';
            else
                cout<<"No definite solution\n";
    }
    else 
    {
        cout<<"Invalid input\n";
    }

}

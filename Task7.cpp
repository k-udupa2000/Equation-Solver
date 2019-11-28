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
	else if(t==0 && g==0)
		sol=numeric_limits<float>::max();
    else if(t==0 && g!=0)
    {
        x="no";
    }
    
    
			
	
}

float Task7::geta()
{
    return a;
}
float Task7::getd()
{
    return d;
}
float Task7::getsol()
{
    return sol;
}
string Task7::getx()
{
    return x;
}
ostream& operator << (ostream& output,Task7  obj){
    obj.solveexpo();
    if(obj.geta()>0 && obj.getd()>0)   
    {
        
        if(obj.getsol()==numeric_limits<float>::max())
            output<<"Infinite solutions\n";
        else if(obj.getx().compare("no")==0)
            output<<"No Solution\n";
        else
            output<<"x="<<fixed<<setprecision(4)<<obj.getsol()<<'\n';
        
    }
    else
    {
        output<<"Invalid input\n";
    }
    return output;
}
    


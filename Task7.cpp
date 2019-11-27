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
ostream& operator << (ostream& output,Task7  obj){
    obj.solveexpo();
    if(obj.geta()>0 && obj.getd()>0)   
    {
        if(obj.getsol()!=numeric_limits<float>::max())
            output<<"x="<<fixed<<setprecision(4)<<obj.getsol()<<'\n';
        else
            output<<"No definite solution\n";
    }
    else
    {
        output<<"Invalid input\n";
    }
    return output;
}
    
void Task7 :: print()
{
    cout << *this << endl;
}
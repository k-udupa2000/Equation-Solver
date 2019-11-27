#include"Base_Task7.h"
Base_Task7::Base_Task7(string input)
{
	eq=input;
}
vector<string> Base_Task7::formbx(string input1)
{
	string A,B,C;
    vector<string> coeff;
    string input;
    A=input1.substr(0,input1.find('^'));
    if(input1[0]=='-')
        input=input1.substr(1,input1.size()-1);
    else
        input=input1;
    int a1=input.find('^');
    int a2=input.find('x');
    A=input.substr(0,a1);
    //case bx
    if(input.find('-')>input.size() && input.find('+')>input.size())
    {
        
        if(input[a1+2]!='x')
             B=input.substr(a1+2,a2-(a1+2));
            
        
        else//case B=1
             B="1";//x
            
        
        C="0";
    }
    //case -bx
    else if(input[a1+2]=='-' && (input.find('-',input.find('-')+1)>input.size()) && input.find('+')>input.size())
    {
        if(input[a1+3]!='x')
            B=input.substr(a1+2,a2-(a1+2));
        else
            B="-1";//-x
        C="0";
    }
    coeff.push_back(A);
    coeff.push_back(B);
    coeff.push_back(C);
    return coeff;

}
vector<string> Base_Task7::formbxplusc(string input1)
{
	string A,B,C;
    vector<string> coeff;
    string input;
    A=input1.substr(0,input1.find('^'));
    
    if(input1[0]=='-')
        input=input1.substr(1,input1.size()-1);
    else
        input=input1;
    int a1=input.find('^');
    int a2=input.find('x');
    int a3=input.find(')');
    
    
   
    if(a3==a2+1)//case C=0;
        coeff=formbx(input);
    
    else//C!=0;
    {
        B=input.substr(a1+2,a2-(a1+2));//bx+c
        if(B.compare("")==0)//x+c
            B="1";
        
        else if(B.compare("-")==0)//-x+c;
            B="-1";
        
        C=input.substr(a2+1,a3-(a2+1));
        coeff.push_back(A);
        coeff.push_back(B);
        coeff.push_back(C);
    }
    return coeff;
}
vector<string> Base_Task7::formcplusbx(string input1)
{
	string A,B,C;
    vector<string> coeff;
    string input;
    A=input1.substr(0,input1.find('^'));
    //cout<<A;
    if(input1[0]=='-')
        input=input1.substr(1,input1.size()-1);
    else
        input=input1;
    
    int a1=input.find('^');
    int a3=input.find('x');
    
   
    
    if(input.find('+')>input.size())//cases- bx,-bx,c-bx
    {
       // cout<<'h';
        if((input.find('-')>input.size()) || (input.find('-')==a1+2 && count(input.begin(),input.begin()+input.size(),'-')==1) )//-bx,bx
        {
               
               B=formbx(input)[1];
               C=formbx(input)[2];
        }
                
        else//c-bx
        {
            int a2;
            if(count(input.begin(),input.begin()+input.size(),'-')==2)
                a2=input.find('-',input.find('-')+1);
            else
                a2=input.find('-');
            
            B=input.substr(a2,a3-(a2));
            if(B.compare("")==0)
                B="1";
        
            else if(B.compare("-")==0)
                B="-1";
            C=input.substr(a1+2,a2-(a1+2));
        }
        
    }
    else//C+bx
    {
        int a2=input.find('+');
        B=input.substr(a2+1,a3-(a2+1));
        if(B.compare("")==0)//C+x
            B="1";
        
        else if(B.compare("-")==0)//c-x;
            B="-1";
        C=input.substr(a1+2,a2-(a1+2));

    }
      
    coeff.push_back(A);
    coeff.push_back(B);
    coeff.push_back(C);
    return coeff;
}
vector<string> Base_Task7::formc(string input)
{
	string A,B,C;
    vector<string> coeff;

    int a1=input.find('^');
    int a2=input.find(')');
    A=input.substr(0,a1);
    B="0";
    C=input.substr(a1+2,a2-(a1+2));
    coeff.push_back(A);
    coeff.push_back(B);
    coeff.push_back(C);
    return coeff;
}
vector<string> Base_Task7::getcoeff(string input)
{
	//  string input;
	//  input=input1.substr(1,input1.size()-2);
    int a=input.find('=');
    string a1=input.substr(0,a);
    string a2=input.substr(a+1,input.size()-a-1);
    
    vector<string> eq;
    vector<string> coeff;
    eq.push_back(a1);
    eq.push_back(a2);
    for(int i=0;i<2;i++)
    {
        
        if(eq[i].find('^')>eq[i].size())
        {
            coeff.push_back(eq[i]);
            coeff.push_back("0");
            coeff.push_back("1");
        }
        else if(eq[i].find('x')>eq[i].size())
        {
                coeff.push_back(formc(eq[i])[0]);
                coeff.push_back(formc(eq[i])[1]);
                coeff.push_back(formc(eq[i])[2]);

        }
        else if(eq[i].find('x')+1==eq[i].find(')'))
        {
                coeff.push_back(formcplusbx(eq[i])[0]);
                coeff.push_back(formcplusbx(eq[i])[1]);
                coeff.push_back(formcplusbx(eq[i])[2]); 
        }
        else
        {
                coeff.push_back(formbxplusc(eq[i])[0]);
                coeff.push_back(formbxplusc(eq[i])[1]);
                coeff.push_back(formbxplusc(eq[i])[2]); 

        }



    }
    return coeff;
}
string Base_Task7::geteq()
{
    return eq;
}

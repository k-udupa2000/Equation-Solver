#include"Task7.h"
int main()
{
    string eq;
    
    
    string input,A,B,C,D,E,F;
    cin>>input;
    int a1=input.find('^');
    int a2=input.find('x');
    int a3=input.find(')');
    int a4=input.find('^',a1+1);
    int a5=input.find('x',a2+1);
    int a6=input.find(')',a3+1);
    
    A=input.substr(0,a1);
    if(a2!=a1+2)
        B=input.substr(a1+2,a2-(a1+2));
    else
        B="1";
    if(a3!=a2+1)
        C=input.substr(a2+2,a3-(a2+2));
    else
        C="0";
    D=input.substr(a3+2,a4-(a3+2));
    if(a5!=a4+2)
        E=input.substr(a4+2,a5-(a4+2));
    else
        E="1";
    if(a6!=a5+1)
        F=input.substr(a5+2,a6-(a5+2));
    else
        F="0";
    
    
    Task_7 t7(stof(A),stof(B),stof(C),stof(D),stof(E),stof(F));
    
    cout<<t7.solveexpo();

}
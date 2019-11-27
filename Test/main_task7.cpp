#include"Task7.h"
vector<string> form3(string input)//C=0
{
    string A,B,C;
    vector<string> coeff;
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
vector<string> form1(string input)//bx+c
{
    string A,B,C;
    vector<string> coeff;
    
    int a1=input.find('^');
    int a2=input.find('x');
    int a3=input.find(')');
    
    A=input.substr(0,a1);
   
    if(a3==a2+1)//case C=0;
        coeff=form3(input);
    
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
vector<string> form2(string input)//c+bx
{
    string A,B,C;
    vector<string> coeff;

    int a1=input.find('^');
    int a3=input.find('x');
    A=input.substr(0,a1);
    if(input.find('+')>input.size())//cases- bx,-bx,c-bx
    {
        if((input.find('-')>input.size()) || (input.find('-')==a1+2 && count(input.begin(),input.begin()+input.size(),'-')==1))//-bx,bx
        {
               A=form3(input)[0];
               B=form3(input)[1];
               C=form3(input)[2];
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
vector<string> form4(string input)
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



int main()
{
    
    
    string input,input1,A,B,C,D,E,F;
    
    cin>>input1;
    input=input1.substr(1,input1.size()-2);
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
                coeff.push_back(form4(eq[i])[0]);
                coeff.push_back(form4(eq[i])[1]);
                coeff.push_back(form4(eq[i])[2]);

        }
        else if(eq[i].find('x')+1==eq[i].find(')'))
        {
                coeff.push_back(form2(eq[i])[0]);
                coeff.push_back(form2(eq[i])[1]);
                coeff.push_back(form2(eq[i])[2]); 
        }
        else
        {
                coeff.push_back(form1(eq[i])[0]);
                coeff.push_back(form1(eq[i])[1]);
                coeff.push_back(form1(eq[i])[2]); 

        }



    }
    
    
//    cout<<stof(coeff[0])<<" "<<stof(coeff[1])<<" "<<stof(coeff[2])<<" ";
       if(stof(coeff[0])>0 && stof(coeff[3])>0)
       {
            Task_7 t7(stof(coeff[0]),stof(coeff[1]),stof(coeff[2]),stof(coeff[3]),stof(coeff[4]),stof(coeff[5]));
            float c=t7.solveexpo();
            if(c!=numeric_limits<float>::max())
                cout<<"x="<<fixed<<setprecision(4)<<t7.solveexpo()<<'\n';
            else
                cout<<"No definite solution\n";
       }
       else
       cout<<"Invalid Input\n";
    
    

}

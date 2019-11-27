#include"Task2.h"

Task2::Task2(string s1, string s2) : Base(s1,s2)
{}

void Task2::get_val_eq1()
{
    int f=0;

    string e1 = get_e1();
    int xi = e1.find("x");
    int yi = e1.find("y");
    //cerr << yi << "yi";
    if(yi==-1)
    {
        int i=0;
        set_b1(0);
        string c = e1.substr(e1.find("=")+1);
        set_c1(stod(c));
        if(e1.substr(0,1).compare("-")==0)
        {
            f=1;
            i+=1;    
        }
        if(xi-i==0)
        {
            if(f==1)
                set_a1(-1);
            else
                set_a1(1);
        }
        else
        {
            string a = e1.substr(i,xi-i);
            if(f==1)
                set_a1(-1*stod(a));
            else
            {
                set_a1(stod(a));
            }
            
        }
    }
    else if(xi==-1)
    {
     int i=0;
        set_a1(0);
        string c = e1.substr(e1.find("=")+1);
        set_c1(stod(c));
        if(e1.substr(0,1).compare("-")==0)
        {
            f=1;
            i+=1;    
        }
        if(yi-i==0)
        {
            if(f==1)
                set_b1(-1);
            else
                set_b1(1);
        }
        else
        {
            string a = e1.substr(i,yi-i);
            if(f==1)
                set_b1(-1*stod(a));
            else
            {
                set_b1(stod(a));
            }
            
        }   
    }
    else if(xi<yi)
    {
        if(e1.substr(yi+1,1).compare("=")!=0 || xi==-1 || yi==-1)
        {
            //cout << e1.substr(yi+1, 1) <<endl;
            cout << "The given equations do not follow the format: ax+by=c / by+ax=c"<<endl <<"Please try again \n";
            flag=1;
            return;
        }
        int i=0;   
        if(e1.substr(0,1).compare("-")==0)
        {
            f=1;
            i+=1;
        }
        if(xi-i==0)
        {
            if(f==1)
                set_a1(-1);
            else
            {
                set_a1(1);
            }
            
        }
        else
        {
            string a1= e1.substr(i,xi-i);
            if(f==1)
                set_a1(-1*(stod(a1)));
            //cout << get_a1();
            else
                set_a1(stod(a1));
        }
        //cout << get_a1() << " a1 \n";
        
        f=0;
        i=xi+1;
        if(e1.substr(xi+1, 1).compare("-")==0)
        {
            f=1;
            i+=1;
        }
        if(yi-i==0 || yi-i==1)
        {
            if(f==1)
                set_b1(-1);
            else
            {
                set_b1(1);
            }
        }
        else
        {
            string b1=e1.substr(i,yi-i);
            if(f==1)
            {
                set_b1(-1*stod(b1));
            }
            else
            {
                set_b1(stod(b1));
            }
        }
        //cout << "b "<<get_b1();
        f=0;
        i=yi+2;
        if(e1.substr(yi+2,1)=="-")
        {
            f=1;
            i+=1;
        }
        string c1 = e1.substr(i,e1.length()-i);
        if(f==1)
        {
            set_c1(-1*stod(c1));
        }
        else
        {
            set_c1(stod(c1));
        }
        //cout << "c " << get_c1();
    }
    else
    {
        if(e1.substr(xi+1,1).compare("=")!=0)
        {
            //cout << "The given equations do not follow the format: ax+by=c / by+ax=c"<<endl <<"Please try again \n";
            flag=1;
            return;
        }
        int i=0;   
        if(e1.substr(0,1).compare("-")==0)
        {
            f=1;
            i+=1;
        }
        if(yi==i)
        {
            if(f==1)
                set_b1(-1);
            else
            {
                set_b1(1);
            }
            
        }
        else{
            string b1= e1.substr(i,yi-i);
            if(f==1)
                set_b1(-1*(stod(b1)));
            else
                set_b1(stod(b1));
        }
        f=0;
        //set_opr(e1.substr(yi+1,yi+2));
        i=yi+1;
        if(e1.substr(yi+1, 1).compare("-")==0)
        {
            f=1;
            i+=1;
        }
        if(xi-i==0 || xi-i==1)
        {
            if(f==1)
                set_a1(-1);
            else
            {
                set_a1(1);
            }
            
        }
        else
        {
            string a1=e1.substr(i,xi-i);
            if(f==1)
            {
                set_a1(-1*stod(a1));
            }
            else
            {
                set_a1(stod(a1));
            }
        }
        f=0;
        i=xi+2;
        if(e1.substr(xi+2,1)=="-")
        {
            f=1;
            i+=1;
        }
        string c1 = e1.substr(i,e1.length()-i);
        if(f==1)
        {
            set_c1(-1*stod(c1));
        }
        else
        {
            set_c1(stod(c1));
        }
    }
}

void Task2::get_val_eq2()
{
    if(flag ==1)
        return;
    int f=0;
    string e2 = get_e2();
    int xi = e2.find("x");
    int yi = e2.find("y");
    if(yi==-1)
    {
        int i=0;
        set_b2(0);
        string c = e2.substr(e2.find("=")+1);
        set_c2(stod(c));
        if(e2.substr(0,1).compare("-")==0)
        {
            f=1;
            i+=1;    
        }
        if(xi-i==0)
        {
            if(f==1)
                set_a2(-1);
            else
                set_a2(1);
        }
        else
        {
            string a = e2.substr(i,xi-i);
            if(f==1)
                set_a2(-1*stod(a));
            else
            {
                set_a2(stod(a));
            }
            
        }
    }
    else if(xi==-1)
    {
     int i=0;
        set_a2(0);
        string c = e2.substr(e2.find("=")+1);
        set_c2(stod(c));
        if(e2.substr(0,1).compare("-")==0)
        {
            f=1;
            i+=1;    
        }
        if(yi-i==0)
        {
            if(f==1)
                set_b2(-1);
            else
                set_b2(1);
        }
        else
        {
            string a = e2.substr(i,yi-i);
            if(f==1)
                set_b2(-1*stod(a));
            else
            {
                set_b2(stod(a));
            }
            
        }   
    }
    else if(xi<yi)
    {
        if(e2.substr(yi+1,1).compare("=")!=0 || xi ==-1 || yi==-1)
        {
            cout << "The given equations do not follow the format: ax+by=c / by+ax=c"<<endl <<"Please try again \n";
            flag=1;
            return;
        }
        int i=0;   
        if(e2.substr(0,1).compare("-")==0)
        {
            f=1;
            i+=1;
        }
        if(xi-i==0)
        {
            if(f==1)
                set_a2(-1);
            else
                set_a2(1);
        }
        else{
            string a1= e2.substr(i,xi-i);
            if(f==1)
                set_a2(-1*(stod(a1)));
            else
                set_a2(stod(a1));
        }
        f=0;
        //cout << "a2 " <<get_a2();
        i=xi+1;
        if(e2.substr(xi+1, 1).compare("-")==0)
        {
            f=1;
            i+=1;
        }
        if(yi-i==0 || yi-i==1)
        {
            if(f==1)
                set_b2(-1);
            else
                set_b2(1);
        }
        else{
            string b1=e2.substr(i,yi-i);
            if(f==1)
            {
                set_b2(-1*stod(b1));
            }
            else
            {
                set_b2(stod(b1));
            }
            
        }
        //cerr << "b2 "<< get_b2();
        f=0;
        i=yi+2;
        if(e2.substr(yi+2,1)=="-")
        {
            f=1;
            i+=1;
        }
        string c1 = e2.substr(i,e2.length()-i);
        if(f==1)
        {
            set_c2(-1*stod(c1));
        }
        else
        {
            set_c2(stod(c1));
        }
        //cout << "c2 "<< get_c2();
    }
    else
    {
        if(e2.substr(xi+1 ,1).compare("=")!=0)
        {
            cout << "The given equations do not follow the format: ax+by=c / by+ax=c"<<endl <<"Please try again \n";
            flag=1;
            return;
        }
        int i=0;   
        if(e2.substr(0,1).compare("-")==0)
        {
            f=1;
            i+=1;
        }
        if(yi-i==0)
        {
            if(f==1)
                set_b2(-1);
            else
                set_b2(1);
        }
        else{
            string b2= e2.substr(i,yi-i);
            if(f==1)
                set_b2(-1*(stod(b2)));
            else
                set_b2(stod(b2));
        }
        f=0;
        //set_opr(e2.substr(yi+1,yi+2));
        i=yi+1;
        if(e2.substr(yi+1, 1).compare("-")==0)
        {
            f=1;
            i+=1;
        }
        if(xi-i==0 || xi-i==1)
        {
            if(f==1)
                set_a2(-1);
            else
                set_a2(1);
        }
        else
        {
            string a2=e2.substr(i,xi-i);
            if(f==1)
            {
                set_a2(-1*stod(a2));
            }
            else
            {
                set_a2(stod(a2));
            }
        }
        f=0;
        i=xi+2;
        if(e2.substr(xi+2,1)=="-")
        {
            f=1;
            i+=1;
        }
        string c2 = e2.substr(i,e2.length()-i);
        if(f==1)
        {
            set_c2(-1*stod(c2));
        }
        else
        {
            set_c2(stod(c2));
        }
    }
}

void Task2::solve()
{
    if(get_a1()==get_a2() && get_b1()==get_b2())
    {
        cout << "No solution for the given equation" << endl;
        return;
    }
    double y;
    if(get_a1()==0)
        y=get_c1()/get_b1();
    if(get_a2()==0)
    {
        //cout << "BOOM" << " " << get_c2()<<get_b2();
        y=get_c2()/get_b2();
    }
    else
    {
        //cout << "Here";
        y = (get_c1()*get_a2()-get_c2()*get_a1())/(get_a2()*get_b1()-get_a1()*get_b2());
    }
    set_y(y);
    //cout << " "<<y << " ";
    double x1 = (get_c1()-get_b1()*y)/get_a1();
    double x2 = (get_c2()-get_b2()*y)/get_a2();
    if(isnanf(x1) || isinf(x1))
        set_x(x2);
    else
    {
        set_x(x1);
    }
    
    //cout << "X IS "<<x;
}


ostream &operator <<(ostream &output, Task2 th)
{    
    th.get_val_eq1();
    th.get_val_eq2();
    th.solve();
    if((isinf(th.get_x()) && isinf(th.get_y())) ||(isnanf(th.get_x()) && isnanf(th.get_y())))
    {
        cout << "No REAL solution for the given equation" << endl;
    }
    cout << "x=" <<setprecision(4) << th.get_x() <<";" <<"y="<<setprecision(4)<<th.get_y()<<endl;
}
void Task2 :: print()
{
    cout << *this;
}
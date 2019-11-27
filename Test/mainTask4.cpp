#include <iostream>
#include <cmath>
#include "Task4.h"
using namespace std;

int main ()
{
    string s1;
    int check;
    cin>>s1;
    Task4 *set=new Task4(s1);
    set->parse(s1);
    /*check=set->find_d(set->geta(),set->getb(),set->getc());
    if(check==0)
    {
        cout << "No solution" << endl;
    }
    else
    {
        vector<double> q=set->solve();
        //cout << set->plus() << endl;
        //cout << set->minus() << endl;
        cout << q[0] << endl;
        cout << q[1] << endl;
    }*/
    cout << set;
    return 0;
}


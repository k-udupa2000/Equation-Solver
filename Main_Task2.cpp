//Main file for reference//
#include"Task2.h"

int main()
{
    string input;
    cin >> input;
    input.erase(0,1);
    input.erase(input.length()-1,1);
    //cout << input << "CHanged";
    //cout << input.substr(0, input.find(";")) << " " <<input.substr(input.find(";")+1);
    Task2 t2 = Task2(input.substr(0, input.find(";")), input.substr(input.find(";")+1));
    t2.get_val_eq1();
    t2.get_val_eq2();
    t2.solve();
    t2.print();
}

//TO DO:
//Case for x+y and all cases without coefficients
//check for -ve coeffecints
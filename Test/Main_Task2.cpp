//Main file for reference//
#include"Task2.h"

int main()
{
    string input;
    cin >> input;
    //input.erase(0,1);                         // TO WORK WITH "" IN INPUT
    //input.erase(input.length()-1,1);
    //cout << input.substr(0, input.find(";")) << " " <<input.substr(input.find(";")+1);
    Task2 t2 = Task2(input.substr(0, input.find(";")), input.substr(input.find(";")+1));
    
    cout << t2;
}
// Code to check task3
#include"Task3.h"
int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    Task3 t(a, b, c, d);
    cout << t.calc_Task_1() << endl;
    cout << t << endl;
    return 0;
}
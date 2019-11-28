#include "Base_Task7.h"
#include "Solver.h"

class Task7 : public Base_Task7, public Solver
{
    float a, b, c, d, e, f, sol;
    string x;

public:
    Task7(string input);
    void solveexpo();
    void print();

    friend ostream &operator<<(ostream &output, Task7 obj);
    float geta();
    float getd();
    float getsol();
    string getx();
};

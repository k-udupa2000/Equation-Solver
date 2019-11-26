#include "Task9.h"

Task9::Task9() : _a(0), _b(0), _c(0), _sol1(0), _sol2(0) {}

Task9::Task9(double a, double b, double c)
: _a(a), _b(b), _c(c), _sol1(0), _sol2(0) {}

Task9::Task9(const Task9& t)
: _a(t._a), _b(t._b), _c(t._c), _sol1(t._sol1), _sol2(t._sol2) {};

Task9::~Task9() {}

void Task9::solve() 
{
        Task1 t1(a-c, b-d, 0);
        _sol1 = t1.solve();
        Task1 t2(-a-c, -b-d, 0);
        _sol2 = t2.solve();
}

ostream& operator<<(ostream& os, const Task9& t)
{
        os << "x = " << t._sol1 << ", " << t.sol2;
        return os;
}

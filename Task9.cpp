#include "Task9.h"

Task9::Task9() : _a(0), _b(0), _c(0), _d(0), _sol1(0), _sol2(0), _isvalid(false) {}

Task9::Task9(float a, float b, float c, float d)
    : _a(a), _b(b), _c(c), _d(d), _sol1(0), _sol2(0), _isvalid(false) {}

Task9::Task9(const Task9 &t)
    : _a(t._a), _b(t._b), _c(t._c), _d(t._d), _sol1(t._sol1), _sol2(t._sol2), _isvalid(t._isvalid){};

Task9::~Task9() {}

void Task9::solve()
{
        if (_a == _c)
        {
                Task1 t2(-_a - _c, 0, _b + _d);
                _sol2 = t2.solve();
        }
        else if ((-1 * _a) == _c)
        {
                Task1 t2(_a - _c, 0, -_b + _d);
                _sol2 = t2.solve();
        }
        else
        {
                Task1 t1(-_a - _c, 0, _b + _d);
                _sol1 = t1.solve();
                _isvalid = true;
                Task1 t2(_a - _c, 0, -_b + _d);
                _sol2 = t2.solve();
        }
}

ostream &operator<<(ostream &os, Task9 &t)
{
        t.solve();
        if (t._isvalid)
                os << setprecision(4) << "x = " << t._sol1 << ", " << t._sol2 << endl;
        else
                os << setprecision(4) << "x = " << t._sol2 << endl;
        return os;
}
void Task9 ::print()
{
        cout << *this;
}

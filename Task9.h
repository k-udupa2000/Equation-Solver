#pragma once
#include "Task1.h"
#include"Solver.h"
#include <cmath>
#include <iostream>
#include <iomanip>

class Task9 : public Solver
{
        public: 
        Task9();
        Task9(float, float, float, float);
        Task9(const Task9&);
        ~Task9();

        void solve();
        bool isValidSolution();
        void print();
        friend ostream& operator<<(ostream&, Task9&);

        private:
            float _a, _b, _c, _d, _sol1, _sol2, _isvalid;
};

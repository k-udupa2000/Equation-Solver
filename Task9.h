#pragma once
#include "Task1.h"

#include <iostream>

class Task9
{
        public: 
        Task9();
        Task9(double, double, double);
        Task9(const Task9&);
        ~Task9();

        void solve();
        friend ostream& operator<<(ostream&, const Task9&);

        private:
            double _a, _b, _c, _d, _sol1, _sol2;
};

#ifndef QUADRATIC_H
#define QUADRATIC_H
#include <math.h>

class Quadratic {
    public:
        Quadratic() {}
        Quadratic(double a_, double b_, double c_) :
        a(a_), b(b_), c(c_) {}

        /**
         * x = (-b \pm sqrt(b^2 - 4ac)) / 2a
        */
        std::pair<double, double> solution() {
            std::pair<double, double> solutions;
            double first = (-1*b + sqrt(pow(b, 2) - 4*a*c)) / (2 * a);
            double second = (-1*b + sqrt(pow(b, 2) - 4*a*c)) / (2 * a);
            solutions.first = first;
            solutions.second = second;
            return solutions;
        }

    public:
        double a, b, c; // at^2 + bt + c = 0
};

#endif

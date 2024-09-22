#include "math_operations.h"
#include <cmath>

extern "C" {
    EXPORT int add(int a, int b) {
        return a + b;
    }

    EXPORT double calculate_hypotenuse(double a, double b) {
        return sqrt(a*a + b*b);
    }
}
#pragma once

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

extern "C" {
    EXPORT int add(int a, int b);
    EXPORT double calculate_hypotenuse(double a, double b);
}
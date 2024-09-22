#include <cmath>
#include <windows.h>

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

extern "C" {
    EXPORT int add(int a, int b) {
        return a + b;
    }

    EXPORT void print_message(const char* message) {
        OutputDebugStringA("Message from C++: ");
        OutputDebugStringA(message);
        OutputDebugStringA("\n");
    }

    EXPORT double calculate_hypotenuse(double a, double b) {
        return sqrt(a*a + b*b);
    }
}
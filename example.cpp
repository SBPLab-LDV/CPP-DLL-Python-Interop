#include <windows.h>
#include "math_operations.h"

extern "C" {
    EXPORT void print_message(const char* message) {
        OutputDebugStringA("Message from C++: ");
        OutputDebugStringA(message);
        OutputDebugStringA("\n");
    }
}
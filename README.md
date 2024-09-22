# CPP-DLL-Python-Interop

This project demonstrates how to create a C++ DLL and use it in Python. It uses CMake for build management and provides a PowerShell script to automate the build and run process. Manual compilation steps using Clang++ are also provided.

## Project Structure

- `example.cpp`: C++ source code containing functions to be exported to DLL.
- `math_operations.h`: Header file declaring math operations.
- `math_operations.cpp`: C++ source code implementing math operations.
- `use_example.py`: Python script demonstrating how to load and use the C++ DLL.
- `CMakeLists.txt`: CMake configuration file for project building.
- `build.ps1`: PowerShell script to automate the build and run process.

## Requirements

- Windows operating system
- Visual Studio 2019 or later (with C++ development tools)
- CMake 3.10 or later
- Python 3.x (Anaconda distribution recommended)
- Clang++ (if using manual compilation)

## Build and Run Instructions

### Using the Automated Script

1. Clone this repository:
   ```bash
   git clone https://github.com/SBPLab-LDV/CPP-DLL-Python-Interop.git
   cd CPP-DLL-Python-Interop
   ```

2. Ensure all necessary tools (Visual Studio, CMake, Python) are installed on your system.

3. If using Anaconda, verify the Python path in `build.ps1` is correct:
   ```powershell
   $pythonPath = "D:\anaconda3\python.exe"
   ```
   Adjust this path as needed.

4. Open PowerShell and set the execution policy to allow script running (if not already set):
   ```powershell
   Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass
   ```

5. Run the build script:
   ```powershell
   .\build.ps1
   ```

### Manual Compilation with Clang++

If you prefer to compile manually using Clang++, follow these steps:

1. Open the "x64 Native Tools Command Prompt for VS 2022" (or your Visual Studio version).

2. Navigate to the project directory:
   ```
   cd path\to\CPP-DLL-Python-Interop
   ```

3. Compile the source files:
   ```
   clang++ -c -std=c++14 math_operations.cpp
   clang++ -c -std=c++14 example.cpp
   ```

4. Link the object files and create the DLL:
   ```
   clang++ -shared -o example.dll math_operations.o example.o -luser32
   ```

5. Run the Python script to test the DLL:
   ```
   python use_example.py
   ```

## Output

If successful, you should see the output of the Python script, showing the results of the C++ functions.

## Troubleshooting

- If you encounter a "running scripts is disabled on this system" error, refer to step 4 in the automated script section to set the execution policy.
- Ensure Visual Studio and CMake paths are added to the system's PATH environment variable.
- If using Anaconda, make sure the Python path in `build.ps1` is correct.
- For manual compilation, ensure Clang++ is properly installed and accessible from the command line.
- When using Clang++ on Windows, you might need additional setup or use MSVC's library paths.
- Depending on your Clang++ version and system configuration, you may need to adjust compilation options.

## Contributing

Issues and pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

[MIT](https://choosealicense.com/licenses/mit/)
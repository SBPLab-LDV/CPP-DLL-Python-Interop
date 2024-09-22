import ctypes
import os

# Get the directory of the current script
current_dir = os.path.dirname(os.path.abspath(__file__))
# Full path to the DLL file
dll_path = os.path.join(current_dir, 'example.dll')

try:
    # Load the DLL
    example_dll = ctypes.CDLL(dll_path)

    # Define function parameters and return types
    example_dll.add.argtypes = [ctypes.c_int, ctypes.c_int]
    example_dll.add.restype = ctypes.c_int

    example_dll.print_message.argtypes = [ctypes.c_char_p]
    example_dll.print_message.restype = None

    example_dll.calculate_hypotenuse.argtypes = [ctypes.c_double, ctypes.c_double]
    example_dll.calculate_hypotenuse.restype = ctypes.c_double

    # Call functions
    sum_result = example_dll.add(5, 3)
    print(f"5 + 3 = {sum_result}")

    example_dll.print_message(b"Hello from Python!")

    hypotenuse = example_dll.calculate_hypotenuse(3.0, 4.0)
    print(f"Hypotenuse length: {hypotenuse}")

except Exception as e:
    print(f"An error occurred: {e}")
import subprocess
import sys
import ctypes

if (len(sys.argv) != 2):
    exit(84)

ex1 = ctypes.CDLL('./ex1.so')
ex1.ex1.argtypes = [ctypes.c_char_p]
file_name = ctypes.c_char_p(sys.argv[1].encode('utf-8'))
#argv = [ctypes.c_char_p(arg.encode('utf-8')) for arg in sys.argv]
python_string = sys.argv[1]
# Create a C-style array of pointers to C strings
c_string = ctypes.c_char_p(python_string.encode('utf-8'))
print(c_string)
ex1.ex1(c_string)
print("ok")
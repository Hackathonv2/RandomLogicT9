import subprocess
import sys
import ctypes

if (len(sys.argv) != 2):
    exit(84)

mylibrary = ctypes.CDLL('./mylibrary.so')
mylibrary.
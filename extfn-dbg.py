#!/usr/bin/env python
#
# Call a C function from Python.
#

import ctypes
import os
import sys

if sys.platform == 'darwin':
    mypyfunc = ctypes.CDLL(os.path.abspath('mypyfunc-dbg.dylib'))
elif sys.platform == 'linux':
    mypyfunc = ctypes.CDLL(os.path.abspath('mypyfunc-dbg.so'))
elif sys.platform == 'win32':
    mypyfunc = ctypes.CDLL(os.path.abspath('mypyfunc-dbg.dll'))
else:
    raise RuntimeError('Not a supported platform.')
    
mypyfunc.mypyfunc.argtypes = [ctypes.c_int, ctypes.c_double]
mypyfunc.mypyfunc.restype = ctypes.c_double

for n in range(0, 80):
    for x in (0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0):
        print(f'The function value f(n={n}, x={x}) = {mypyfunc.mypyfunc(n, x)}')

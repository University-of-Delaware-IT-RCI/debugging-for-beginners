#!/usr/bin/env python
#
# Malformed Python code
#

def g(x):
    return 1 / (x + 0.5)

def f(x):
    return x - 2

def main_program():
    print(f'f(1.5)={f(1.5)}')
    print(f'g(f(1.5))={g(f(1.5))}')

if __name__ == '__main__':
    main_program()

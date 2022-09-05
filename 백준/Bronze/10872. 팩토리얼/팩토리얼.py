import sys

def fact(n):
    if n == 0:
        return 1
    elif n <= 2:
        return n
    else:
        return n * fact(n-1)

print(fact(int(sys.stdin.readline())))
# Silver 4
# 76ms

import sys
T = int(sys.stdin.readline())

for _ in range(T):
    check = sys.stdin.readline().rstrip()
    stk = []
    for i in check:
        if i == '(':
            stk.append(i)
        else:
            if not stk:
                print('NO')
                break
            elif stk[-1] == ')':
                print('NO')
                break
            elif stk[-1] == '(':
                stk.pop()
    else:
        if stk:
            print('NO')
        else:
            print('YES')

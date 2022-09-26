# silver 2
# 새로운 스택에 집어넣었다 뺐다를 반복하면서 기존에 정의된 stk과 같다면 cal 프린트, 아니면 NO 프린트

from collections import deque
import sys
N = int(sys.stdin.readline())
cnt = 0
stk = []
cal = []
flag = True

for _ in range(N):
    a = int(sys.stdin.readline())

    while cnt < a:
        cnt += 1
        stk.append(cnt)
        cal.append('+')

    if stk[-1] == a:
        stk.pop()
        cal.append('-')
    else:
        flag = False
        break

if flag:
    print(*cal)
else:
    print('NO')

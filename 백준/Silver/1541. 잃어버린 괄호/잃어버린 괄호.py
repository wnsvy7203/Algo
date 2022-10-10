import sys
from collections import deque

exp = sys.stdin.readline().rstrip()
mid = []

nums = ''
for i in range(len(exp)):
    if exp[i].isdigit():
        nums += exp[i]
    else:
        mid.append(nums)
        mid.append(exp[i])
        nums = ''
else:
    mid.append(nums)

for i in range(len(mid)):
    if mid[i] == '+':
        mid[i+1] = str(int(mid[i-1]) + int(mid[i+1]))
        mid[i-1] = '0'

res = deque()
cal = []
for i in range(len(mid)):
    if mid[i].isdigit() and mid[i] != '0':
        res.append(int(mid[i]))
    elif mid[i] == '-':
        cal.append(mid[i])

while cal:
    cal.pop()
    a = res.popleft()
    b = res.popleft()

    res.appendleft(a - b)

print(res[-1])

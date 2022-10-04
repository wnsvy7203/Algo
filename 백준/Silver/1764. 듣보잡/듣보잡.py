# silver 4
# 0ms

import sys
N, M = map(int, input().split())

not_listen = {}
for i in range(N):
    put = sys.stdin.readline().rstrip()
    not_listen[put] = i

ans = []
for _ in range(M):
    put = sys.stdin.readline().rstrip()
    if put in not_listen:
        ans.append(put)

ans.sort()
print(len(ans))
for i in ans:
    print(i)

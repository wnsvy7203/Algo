# silver 2

import sys


N, M, B = map(int, sys.stdin.readline().split())
land = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

minV = float('inf')
res = 0

for height in range(257):
    s = 0
    e = 0
    for i in range(N):
        for j in range(M):
            if land[i][j] >= height:
                e += land[i][j] - height
            else:
                s += height - land[i][j]

    if s > e + B:
        continue

    cnt = s + (e * 2)
    if cnt <= minV:
        minV = cnt
        res = height

print(minV, res)

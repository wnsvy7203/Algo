# silver 2

import sys


N, M, B = map(int, sys.stdin.readline().split())
land = []

for _ in range(N):
    land += list(map(int, sys.stdin.readline().split()))

minV = float('inf')
res = 0

for height in range(257):
    s = 0
    e = 0
    for i in range(N*M):
        if land[i] >= height:
            e += land[i] - height
        else:
            s += height - land[i]

    if s > e + B:
        continue

    cnt = s + (e * 2)
    if cnt <= minV:
        minV = cnt
        res = height

print(minV, res)
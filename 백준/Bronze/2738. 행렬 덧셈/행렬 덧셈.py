import sys
N, M = map(int, sys.stdin.readline().split())

arr1 = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
arr2 = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

arr3 = [[0] * M for _ in range(N)]
for i in range(N):
    for j in range(M):
        arr3[i][j] = arr1[i][j] + arr2[i][j]

for i in range(N):
    for j in range(M):
        print(arr3[i][j], end=' ')
    print()
        
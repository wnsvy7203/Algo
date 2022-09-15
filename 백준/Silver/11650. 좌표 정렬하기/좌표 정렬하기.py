N = int(input()) # 1 <= N <= 100000

arr = [list(map(int, input().split())) for _ in range(N)]

arr.sort()

for i in range(N):
  print(*arr[i])
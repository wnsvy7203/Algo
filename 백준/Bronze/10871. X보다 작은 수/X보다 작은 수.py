N, X = map(int, input().split())
arr = list(map(int, input().split()))
for i in range(len(arr)):
    if arr[i] < X:
        print(arr[i], end=' ')
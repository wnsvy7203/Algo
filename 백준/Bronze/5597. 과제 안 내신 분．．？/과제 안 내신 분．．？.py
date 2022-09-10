import sys

arr = [int(sys.stdin.readline()) for _ in range(28)]
cnt = [1] * 31
for i in range(1, 31):
    if i in arr:
        cnt[i] -= 1

for i in range(1, 31):
    if cnt[i]:
        print(i)
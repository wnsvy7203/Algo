# silver 3
# 0ms

N = int(input())

memo = [i for i in range(1001)]
memo[2] = 2
memo[3] = 3

for i in range(4, 1001):
    memo[i] = memo[i-1] + memo[i-2]

print(memo[N] % 10007)

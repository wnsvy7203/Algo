from math import isqrt

n = int(input())

memo = [4 for _ in range(50001)]
memo[1] = 1
memo[2] = 2
memo[3] = 3

for i in range(4, 50001):
    if isqrt(i) == i ** (1/2):
        memo[i] = 1
    else:
        j = 1
        while j ** 2 <= i:
            memo[i] = min(memo[i], memo[i-j**2] + memo[j**2])
            j += 1

print(memo[n])

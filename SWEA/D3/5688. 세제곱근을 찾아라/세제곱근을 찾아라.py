from math import pow
T = int(input())

for tc in range(1, T+1):
    N = int(input())
    x = round(pow(N, 1/3), 2)
    print(f'#{tc}', end=' ')
    if x == int(x):
        print(int(x))
    else:
        print(-1)

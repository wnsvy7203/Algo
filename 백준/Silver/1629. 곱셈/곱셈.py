A, B, C = map(int, input().split())


def division(a, b, c):
    if b == 1:
        return a % c

    temp = division(a, b // 2, c)

    if not b % 2:
        return (temp * temp) % c
    else:
        return (temp * temp * a) % c


print(division(A, B, C))
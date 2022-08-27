# a: 공통부분이 면인 경우
# b: 공통부분이 선인 경우
# c: 공통부분이 점인 경우
# d: 공통부분 없는 경우

# 좌표 값은 x, y, p, q로 주어지고, 1 <= x, y, p, q <= 50000의 정수로 제한된다.

for _ in range(4):
    x1, y1, p1, q1, x2, y2, p2, q2 = map(int, input().split())

    # print(x1, y1, p1, q1, x2, y2, p2, q2)

    if p1 < x2 or p2 < x1 or q1 < y2 or q2 < y1:
        print('d')
    elif p1 == x2 or p2 == x1:
        if q1 == y2 or q2 == y1:
            print('c')
        else:
            print('b')
    elif q1 == y2 or q2 == y1:
        print('b')
    else:
        print('a')


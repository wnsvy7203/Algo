T = int(input())
for _ in range(T):
    square = [list(map(int, input().split())) for _ in range(4)]

    lst = [0] * 6
    
    lst[0] = abs(square[0][0] - square[1][0]) + abs(square[0][1] - square[1][1])
    lst[1] = abs(square[0][0] - square[2][0]) + abs(square[0][1] - square[2][1])
    lst[2] = abs(square[0][0] - square[3][0]) + abs(square[0][1] - square[3][1])
    lst[3] = abs(square[1][0] - square[2][0]) + abs(square[1][1] - square[2][1])
    lst[4] = abs(square[1][0] - square[3][0]) + abs(square[1][1] - square[3][1])
    lst[5] = abs(square[2][0] - square[3][0]) + abs(square[2][1] - square[3][1])

    lst.sort()

    if lst[0] == lst[1] == lst[2] == lst[3] and lst[4] == lst[5]:
        print(1)
    else:
        print(0)

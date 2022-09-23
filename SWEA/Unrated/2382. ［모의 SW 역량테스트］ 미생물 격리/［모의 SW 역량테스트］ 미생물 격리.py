T = int(input())

for x in range(1, T+1):
    N, M, K = map(int, input().split())
    micro = [list(map(int, input().split())) for _ in range(K)]
    for mi in micro:
        mi[3] -= 1

    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]
    for _ in range(M):
        for mi in micro:
            mi[0] += dr[mi[3]]
            mi[1] += dc[mi[3]]

            if mi[0] == 0 or mi[1] == 0 or mi[0] == N-1 or mi[1] == N-1:
                mi[2] //= 2
                if not mi[3] % 2:
                    mi[3] += 1
                else:
                    mi[3] -= 1

        micro.sort()
        # print(micro)

        for i in range(K-1, -1, -1):
            for j in range(1, i+1):
                if micro[i][0] == micro[i-j][0] and micro[i][1] == micro[i-j][1]:
                    micro[i][2] += micro[i-j][2]
                    micro[i-j][2] = 0

    res = 0
    for mi in micro:
        res += mi[2]

    print(f'#{x} {res}')

import sys
from collections import deque

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]


def bfs(y, x, size):
    dist = [[0] * N for _ in range(N)]
    visited = [[0] * N for _ in range(N)]

    que = deque([(y, x)])
    visited[y][x] = 1
    lst = []

    while que:
        r, c = que.popleft()
        for d in range(4):
            nr = r + dr[d]
            nc = c + dc[d]
            if 0 <= nr < N and 0 <= nc < N and not visited[nr][nc]:
                if graph[nr][nc] <= size:
                    que.append((nr, nc))
                    visited[nr][nc] = 1
                    dist[nr][nc] = dist[r][c] + 1
                    if graph[nr][nc] < size and graph[nr][nc]:
                        lst.append((nr, nc, dist[nr][nc]))

    return sorted(lst, key=lambda z: (-z[2], -z[0], -z[1]))


N = int(sys.stdin.readline())
graph = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
temp = []
a, b, shark = 0, 0, 2

for i in range(N):
    for j in range(N):
        if graph[i][j] == 9:
            a, b = i, j

cnt = 0
res = 0
while True:
    temp = bfs(a, b, shark)

    if not temp:
        break

    na, nb, far = temp.pop()

    res += far
    graph[a][b] = 0
    graph[na][nb] = 0

    a, b = na, nb
    cnt += 1
    if cnt == shark:
        shark += 1
        cnt = 0

print(res)
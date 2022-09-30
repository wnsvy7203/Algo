

def queen(v):
    for i in range(v):
        if visited[v] == visited[i] or abs(visited[v] - visited[i]) == abs(v - i):
            return False
    return True


def dfs(v):
    global cnt
    if v == N:
        cnt += 1
    else:
        for i in range(N):
            visited[v] = i
            if queen(v):
                dfs(v+1)


N = int(input())
cnt = 0
visited = [0] * N
dfs(0)

print(cnt)

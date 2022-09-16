def bfs(v):
    visited = [0] * 101
    queue = [v]
    visited[v] = 1
    while queue:
        t = queue.pop(0)
        for a in adjList[t]:
            if not visited[a]:
                queue.append(a)
                visited[a] = visited[t] + 1

    idx = []

    for b in range(101):
        if visited[b] == max(visited):
            idx.append(b)

    return max(idx)


for tc in range(1, 11):
    N, start = map(int, input().split())
    arr = list(map(int, input().split()))

    adjList = [[] for _ in range(101)]
    for i in range(0, N, 2):
        if arr[i+1] not in adjList[arr[i]]:
            adjList[arr[i]].append(arr[i+1])
    print(f'#{tc} {bfs(start)}')

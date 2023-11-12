#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> graph[10001];

int bfs_max(int x)
{
    int visited[n+1];
    fill_n(&visited[0], n+1, -1);
    visited[x] = 0;
    
    queue<int> que;
    que.push(x);

    while (!que.empty())
    {
        int f = que.front();
        que.pop();

        for (pair<int, int> p : graph[f])
        {
            if (visited[p.first] == -1)
            {
                que.push(p.first);
                visited[p.first] = visited[f] + p.second;
            }
        }
    }

    int res = 0, idx = 0;
    for (int i = 0; i < n+1; i++)
        if (res < visited[i])
        {
            res = visited[i];
            idx = i;
        }

    return idx;
}

int bfs(int x)
{
    int visited[n+1];
    fill_n(&visited[0], n+1, -1);
    visited[x] = 0;
    
    queue<int> que;
    que.push(x);

    while (!que.empty())
    {
        int f = que.front();
        que.pop();

        for (pair<int, int> p : graph[f])
        {
            if (visited[p.first] == -1)
            {
                que.push(p.first);
                visited[p.first] = visited[f] + p.second;
            }
        }
    }

    return *max_element(visited, visited+n+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    cout << bfs(bfs_max(1));
}
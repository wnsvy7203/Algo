// 07192051

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, s, e, m;
vector<int> graph[101];
queue<int> que;

int visited[101];

void bfs()
{
    while (!que.empty())
    {
        int front = que.front();
        que.pop();

        for (int i = 0; i < graph[front].size(); i++)
            if (!visited[graph[front][i]])
            {
                que.push(graph[front][i]);
                visited[graph[front][i]] = visited[front] + 1;
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> e >> m;
    
    int u, v;

    while (m--)
    {
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    que.push(s);
    visited[s] = 1;

    bfs();

    cout << visited[e] - 1;
}
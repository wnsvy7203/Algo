//

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int a, b, N, M;
vector<int> graph[100001];
int visited[100001];

queue<int> que;

int bfs(int x, int y)
{
    que.push(x);
    visited[x] = 1;

    while (!que.empty())
    {
        int f = que.front();
        que.pop();

        if (f == y)
            break;

        for (int i = 0; i < graph[f].size(); i++)
        {
            if (!visited[graph[f][i]])
            {
                que.push(graph[f][i]);
                visited[graph[f][i]] = visited[f] + 1;
            }
        }
    }

    return visited[y] - 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> N >> M;

    while (M--)
    {
        int u, v;

        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << bfs(a, b);
}
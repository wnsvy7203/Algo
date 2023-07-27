// 128ms

#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100001

using namespace std;

int N, M, R;
vector<int> graph[MAX];
int visited[MAX];

queue<int> que;

void bfs()
{
    que.push(R);
    int cnt = 1;
    visited[R] = cnt;

    while (!que.empty())
    {
        int r = que.front();
        que.pop();

        sort(graph[r].begin(), graph[r].end());

        for (int i = 0; i < graph[r].size(); i++)
        {
            if (!visited[graph[r][i]])
            {
                cnt++;
                que.push(graph[r][i]);
                visited[graph[r][i]] = cnt;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> R;

    while (M--)
    {
        int u, v;

        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs();

    for (int i = 1; i <= N; i++)
        cout << visited[i] << '\n';
}
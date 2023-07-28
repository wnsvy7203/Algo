// 88ms

#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100001

using namespace std;

int N, M, R;
vector<int> graph[MAX];

queue<int> que;
long long int visited[MAX];
long long int order[MAX];

void bfs(int s)
{
    que.push(s);
    visited[s] = 1;
    order[s] = 1;

    int cnt = 1;
    while (!que.empty())
    {
        int r = que.front();
        que.pop();

        sort(graph[r].begin(), graph[r].end());

        for (int i = 0; i < graph[r].size(); i++)
            if (!visited[graph[r][i]])
            {
                cnt++;
                que.push(graph[r][i]);
                visited[graph[r][i]] = visited[r] + 1;
                order[graph[r][i]] = cnt;
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

    bfs(R);

    long long int ans = 0;

    for (int i = 1; i <= N; i++)  
        ans += order[i] * (visited[i] - 1);

    cout << ans;
}
// 36ms

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, ans;
int res[10001];
vector<int> graph[10001];

queue<int> que;
bool visited[10001];

int bfs(int s)
{
    memset(visited, 0, sizeof(visited));
    que.push(s);

    int cnt = 0;

    while (!que.empty())
    {
        int r = que.front();
        que.pop();

        if (visited[r])
            continue;
        else
        {
            visited[r] = 1;
            cnt++;
        }
        
        for (int i = 0; i < graph[r].size(); i++)
        {
            if (!visited[graph[r][i]])
                que.push(graph[r][i]);

        }
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    while (M--)
    {
        int u, v;

        cin >> u >> v;

        graph[v].push_back(u);
    }

    
    for (int i = 1; i <= N; i++)
    {
        res[i] = bfs(i);
        
        if (ans < res[i])
            ans = res[i];
    }

    for (int i = 1; i <= N; i++)
        if (res[i] == ans)
            cout << i << ' ';
}
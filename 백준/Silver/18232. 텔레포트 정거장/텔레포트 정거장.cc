// 4ms

#include <iostream>
#include <queue>

using namespace std;

int N, M, S, E;
int visited[300001];

vector<int> graph[300001];
queue<int> que;

int bfs(int s, int e)
{
    que.push(s);
    visited[s] = 1;

    int res = 0;

    while (!que.empty())
    {
        int f = que.front();
        que.pop();

        if (f == e)
            break;

        for (int i = 0; i < graph[f].size(); i++)
            if (!visited[graph[f][i]])
            {
                que.push(graph[f][i]);
                visited[graph[f][i]] = visited[f]+1;
            }
        
        if (f-1 > 0 && !visited[f-1])
        {
            que.push(f-1);
            visited[f-1] = visited[f]+1;
        }
        
        if (f+1 <= 300000 && !visited[f+1])
        {
            que.push(f+1);
            visited[f+1] = visited[f]+1;

        }
    }

    return visited[e] - 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> S >> E;

    int x, y;

    while (M--)
    {
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    cout << bfs(S, E);
}
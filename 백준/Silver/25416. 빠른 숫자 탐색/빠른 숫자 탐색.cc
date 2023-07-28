// 92ms

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int r, c;
int graph[5][5];

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

queue<tuple<int, int, int>> que;
bool visited[5][5];

void bfs(int x, int y, int a, int b)
{
    que.push({x, y, 0});

    while (!que.empty())
    {
        int i = get<0>(que.front());
        int j = get<1>(que.front());
        int cnt = get<2>(que.front());

        que.pop();

        if (graph[i][j] == 1)
        {
            cout << cnt;
            return;
        }

        visited[i][j] = 1;

        for (int d = 0; d < 4; d++)
        {
            int ni = i + di[d];
            int nj = j + dj[d];

            if (ni < 0 || ni >= 5 || nj < 0 || nj >= 5)
                continue;

            if (!visited[ni][nj] && graph[ni][nj] != -1)
                que.push({ni, nj, cnt+1});

        }
    }

    if (!visited[a][b])
    {
        cout << -1;
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            cin >> graph[i][j];

            if (graph[i][j] == 1)
            {
                a = i;
                b = j;
            }

        }

    cin >> r >> c;

    bfs(r, c, a, b);
}
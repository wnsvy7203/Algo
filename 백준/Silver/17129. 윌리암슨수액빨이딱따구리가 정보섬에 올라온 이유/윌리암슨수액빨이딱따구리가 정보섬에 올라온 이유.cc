// 12ms

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
char second_floor[3001][3001];
bool visited[3001][3001];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

queue<tuple<int, int, int>> que;

void bfs(int i, int j)
{
    que.push({i, j, 0});
    visited[i][j] = 0;

    while (!que.empty())
    {
        int r = get<0>(que.front());
        int c = get<1>(que.front());
        int cnt = get<2>(que.front());

        que.pop();

        if (second_floor[r][c] == '3' || second_floor[r][c] == '4' || second_floor[r][c] == '5')
        {
            cout << "TAK\n" << cnt;
            return;
        }

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;

            if (!visited[nr][nc] && second_floor[nr][nc] != '1')
            {
                que.push({nr, nc, cnt+1});
                visited[nr][nc] = 1;
            }
        }
    }

    cout << "NIE";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;

        for (int j = 0; j < m; j++)
            second_floor[i][j] = str[j];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (second_floor[i][j] == '2')
                bfs(i, j);
}
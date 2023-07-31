// 40ms

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int M, N, K;
int board[101][101];
bool visited[101][101];

int area[10001];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

stack<pair<int, int>> stk;

int dfs(int x, int y)
{
    stk.push({x, y});
    visited[x][y] = 1;

    int res = 1;

    while (!stk.empty())
    {
        int r = stk.top().first;
        int c = stk.top().second;

        stk.pop();

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= M || nc < 0 || nc >= N)
                continue;
            
            if (!board[nr][nc] && !visited[nr][nc])
            {
                stk.push({nr, nc});
                visited[nr][nc] = 1;
                res++;
            }
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> K;

    while (K--)
    {
        int a, b, c, d;

        cin >> a >> b >> c >> d;

        for (int i = b; i < d; i++)
            for (int j = a; j < c; j++)
                board[i][j] = 1;
    }

    int cnt = 0;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (!board[i][j] && !visited[i][j])
            {
                area[cnt] = dfs(i, j);
                cnt++;
            }

    sort(area, area+cnt);

    cout << cnt << '\n';

    for (int i = 0; i < cnt; i++)
        cout << area[i] << ' ';
}
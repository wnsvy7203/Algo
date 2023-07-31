// 16ms

#include <iostream>
#include <stack>

using namespace std;

int n, m;
int board[501][501];
bool visited[501][501];

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

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            
            if (board[nr][nc] && !visited[nr][nc])
            {
                res++;
                stk.push({nr, nc});
                visited[nr][nc] = 1;
            }
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    int area = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] && !visited[i][j])
            {
                cnt++;
                area = max(area, dfs(i, j));
            }
    
    cout << cnt << '\n' << area;
}
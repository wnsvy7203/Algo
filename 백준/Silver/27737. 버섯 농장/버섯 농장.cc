// 

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N, M, K;
bool board[101][101];
bool visited[101][101];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int dfs(int i, int j)
{
    queue<pair<int, int>> que;
    que.push({i, j});
    visited[i][j] = 1;

    int cnt = 1;

    while (!que.empty())
    {
        int r = que.front().first;
        int c = que.front().second;

        que.pop();

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;

            if (!visited[nr][nc] && !board[nr][nc])
            {
                que.push({nr, nc});
                visited[nr][nc] = 1;
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!visited[i][j] && !board[i][j])
            {
                int x = dfs(i, j);

                ans += ceil((double)x / K);
            }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!visited[i][j] && !board[i][j])
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
    
    if (ans > 0 && M >= ans)
        cout << "POSSIBLE\n" << M - ans;
    else
        cout << "IMPOSSIBLE";
}
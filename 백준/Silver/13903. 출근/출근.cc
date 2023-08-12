// 16ms

#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#define MAX 100000000

using namespace std;

int R, C, N;

bool board[1001][1001];
int visited[1001][1001];

int dr[10];
int dc[10];

queue<pair<int, int>> que;

void bfs()
{
    while (!que.empty())
    {
        int r = que.front().first;
        int c = que.front().second;

        que.pop();

        if (r == R-1)
        {
            cout << visited[r][c] - 1;
            return;
        }

        for (int d = 0; d < N; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;

            if (!visited[nr][nc] && board[nr][nc])
            {
                visited[nr][nc] = visited[r][c] + 1;
                que.push({nr, nc});
            }
        }
    }
    cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> board[i][j];

    cin >> N;
    for (int d = 0; d < N; d++)
    {
        cin >> dr[d] >> dc[d];
    }
    
    for (int i = 0; i < C; i++)
        if (board[0][i])
        {
            visited[0][i] = 1;
            que.push({0, i});
        }
    
    bfs();
}
// 108ms

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;

int board[65][65];
bool visited[65][65];

int dr[2] = {1, 0};
int dc[2] = {0, 1};

queue<pair<int, int>> que;

bool bfs()
{
    que.push({0, 0});
    visited[0][0] = 1;
    
    while (!que.empty())
    {
        int r = que.front().first;
        int c = que.front().second;

        que.pop();

        if (board[r][c] == -1)
            return 1;

        for (int d = 0; d < 2; d++)
        {
            int nr = r + dr[d]*board[r][c];
            int nc = c + dc[d]*board[r][c];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;
            
            if (!visited[nr][nc])
            {
                visited[nr][nc] = 1;
                que.push({nr, nc});
            }
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    bool flag = bfs();

    if (flag)
        cout << "HaruHaru";
    else
        cout << "Hing";

}
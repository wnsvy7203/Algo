// 36ms

#include <iostream>
#include <queue>

using namespace std;

int N, M;
char board[101][101];

queue<pair<int, int>> que;
bool visited[101][101];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int bfs(int x, int y, char color)
{
    que.push({x, y});

    int cnt = 0;

    while (!que.empty())
    {
        int r = que.front().first;
        int c = que.front().second;

        que.pop();

        if (visited[r][c])
            continue;
        else
        {
            visited[r][c] = 1;
            cnt++;
        }
        
        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= M || nc < 0 || nc >= N)
                continue;
            
            if (!visited[nr][nc] && board[nr][nc] == color)
                que.push({nr, nc});
        }
    }

    return cnt * cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        string str;

        cin >> str;

        for (int j = 0; j < N; j++)
            board[i][j] = str[j];
    }

    int white = 0;
    int blue = 0;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (!visited[i][j])
                if (board[i][j] == 'W')
                    white += bfs(i, j, 'W');
                else
                    blue += bfs(i, j, 'B');

    cout << white << ' ' << blue;
}
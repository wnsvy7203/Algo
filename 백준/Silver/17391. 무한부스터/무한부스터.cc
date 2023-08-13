// 408ms

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int board[301][301];
int visited[301][301];

int dr[2] = {1, 0};
int dc[2] = {0, 1};

queue<tuple<int, int, int>> que;

void bfs()
{
    que.push({1, 1, board[1][1]});
    visited[1][1] = 1;

    while (!que.empty())
    {
        int r = get<0>(que.front());
        int c = get<1>(que.front());
        int booster = get<2>(que.front());

        que.pop();

        if (r == N && c == M)
        {
            cout << visited[N][M]-1;
            return;
        }
        
        for (int i = 1; i <= booster; i++)
            for (int d = 0; d < 2; d++)
            {
                int nr = r + dr[d] * i;
                int nc = c + dc[d] * i;

                if (nr <= 0 || nr > N || nc <= 0 || nc > M)
                    continue;

                if (!visited[nr][nc])
                {
                    que.push({nr, nc, board[nr][nc]});
                    visited[nr][nc] = visited[r][c] + 1;
                }
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> board[i][j];
    
    bfs();
}
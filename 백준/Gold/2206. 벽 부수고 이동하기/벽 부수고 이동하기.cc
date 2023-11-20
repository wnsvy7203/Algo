#include <iostream>
#include <queue>
#include <tuple>

#define MAX 1001

using namespace std;

int N, M;
string str;

int board[MAX][MAX];
int visited[MAX][MAX][2];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

queue<tuple<int, int, int>> que;
int bfs()
{
    que.push({1, 1, 0});
    visited[1][1][0] = 1;

    while (!que.empty())
    {
        int r = get<0>(que.front());
        int c = get<1>(que.front());
        int flag = get<2>(que.front());
        que.pop();

        if (r == N && c == M)
            return visited[N][M][flag];

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr <= 0 || nr > N || nc <= 0 || nc > M)
                continue;
            
            if (!visited[nr][nc][flag])
            {
                if (!board[nr][nc])
                {
                    visited[nr][nc][flag] = visited[r][c][flag] + 1;
                    que.push({nr, nc, flag});
                }
                else if (!flag && board[nr][nc])
                {
                    visited[nr][nc][flag+1] = visited[r][c][flag] + 1;
                    que.push({nr, nc, flag+1});
                }
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> str;
        for (int j = 0; j < M; j++)
            board[i][j+1] = str[j]-48;
    }

    cout << bfs();
}

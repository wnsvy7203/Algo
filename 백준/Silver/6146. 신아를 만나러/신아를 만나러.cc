// 16ms

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int X, Y, N;
bool board[1001][1001];
int visited[1001][1001];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

queue<pair<int, int>> que;

void bfs()
{
    que.push({500, 500});
    visited[500][500] = 1;

    while (!que.empty())
    {
        int r = que.front().first;
        int c = que.front().second;

        que.pop();
        
        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr > 1000 || nc < 0 || nc > 1000)
                continue;

            if (!board[nr][nc] && !visited[nr][nc])
            {
                que.push({nr, nc});
                visited[nr][nc] = visited[r][c] + 1;

                if (nr == X+500 && nc == Y+500)
                {
                    cout << visited[nr][nc] - 1;
                    return;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> X >> Y >> N;

    int A_i, B_i;

    while (N--)
    {
        cin >> A_i >> B_i;

        board[A_i+500][B_i+500] = 1;        
    }

    bfs();
}
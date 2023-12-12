#include <iostream>
#include <queue>
#include <tuple>

#define INF 100*100

using namespace std;

int N, M;
bool board[101][101];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
string nums;

int visited[101][101];
queue<pair<int, int>> que;
void dijkstra()
{
    fill_n(&visited[0][0], 101*101, INF);
    que.push({1, 1});
    visited[1][1] = 0;

    while (!que.empty())
    {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr <= 0 || nr > N || nc <= 0 || nc > M)
                continue;
            
            if (board[nr][nc] && visited[nr][nc] > visited[r][c] + 1)
            {
                visited[nr][nc] = visited[r][c] + 1;
                que.push({nr, nc});
            }
            else if (!board[nr][nc] && visited[nr][nc] > visited[r][c])
            {
                visited[nr][nc] = visited[r][c];
                que.push({nr, nc});
            }
        }
    }

    cout << visited[N][M];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> nums;
        for (int j = 0; j < M; j++)
            board[i][j+1] = nums[j]-48;
    }

    dijkstra();
}
// 

#include <iostream>
#include <queue>

using namespace std;

int N, M, X, Y;
int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int board[501][501];
int visited[501][501];

queue<pair<int, int>> que;

void bfs()
{
    que.push({X, Y});
    visited[X][Y] = 1;

    while (!que.empty())
    {
        int r = que.front().first;
        int c = que.front().second;

        que.pop();

        for (int d = 0; d < 8; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr <= 0 || nr > N || nc <= 0 || nc > N)
                continue;
            
            if (!visited[nr][nc])
            {
                que.push({nr, nc});
                visited[nr][nc] = visited[r][c] + 1;
            }
        }
    }
}

int main()
{
    cin >> N >> M >> X >> Y;

    bfs();

    vector<int> visit;

    int A, B;
    while (M--)
    {
        cin >> A >> B;

        visit.push_back(visited[A][B] - 1);
    }

    for (int i = 0; i < visit.size(); i++)
        cout << visit[i] << ' ';
}

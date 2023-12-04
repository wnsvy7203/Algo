#include <iostream>
#include <queue>

#define INF 501*501

using namespace std;

int N, M;  // N: 위험한 구역의 수, M: 죽음의 구역의 수
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int board[501][501];
int visited[501][501];

queue<pair<int, int>> que;
void dijkstra()
{
    fill_n(&visited[0][0], 501*501, INF);
    que.push({0, 0});
    visited[0][0] = 0;
    
    while (!que.empty())
    {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr > 500 || nc < 0 || nc > 500)
                continue;
            
            if (board[nr][nc] != 2 && visited[nr][nc] > visited[r][c] + board[nr][nc])
            {
                visited[nr][nc] = visited[r][c] + board[nr][nc];
                que.push({nr, nc});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while (N--)
    {
        int X1, X2, Y1, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        if (X1 > X2)
            swap(X1, X2);
        if (Y1 > Y2)
            swap(Y1, Y2);

        for (int i = X1; i <= X2; i++)
            for (int j = Y1; j <= Y2; j++)
                board[i][j] = 1;
    }

    cin >> M;
    while (M--)
    {
        int X1, X2, Y1, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        if (X1 > X2)
            swap(X1, X2);
        if (Y1 > Y2)
            swap(Y1, Y2);

        for (int i = X1; i <= X2; i++)
            for (int j = Y1; j <= Y2; j++)
                board[i][j] = 2;
    }

    dijkstra();
    if (visited[500][500] == INF)
        cout << -1;
    else
        cout << visited[500][500];
}
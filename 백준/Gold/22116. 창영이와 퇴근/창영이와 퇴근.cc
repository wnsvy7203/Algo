#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

// 2 * 10의 9승 => 20억
// int 범위에서 무한대를 나타낼 때 쓴다.
#define INF 2e9

using namespace std;

int N, board[1001][1001];
void input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
}

priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pque;
int visited[1001][1001];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
long long ans = 0;
void dijkstra()
{
    fill_n(&visited[0][0], 1001 * 1001, INF);
    pque.push({0, 1, 1});
    visited[1][1] = 0;

    while (!pque.empty())
    {
        long long height = get<0>(pque.top());
        int r = get<1>(pque.top());
        int c = get<2>(pque.top());
        pque.pop();

        ans = max(ans, height);
        if (r == N && c == N)
        {
            cout << ans;
            break;
        }

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr <= 0 || nr > N || nc <= 0 || nc > N)
                continue;

            if (visited[nr][nc] > abs(board[nr][nc] - board[r][c]))
            {
                visited[nr][nc] = abs(board[nr][nc] - board[r][c]);
                pque.push({visited[nr][nc], nr, nc});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    dijkstra();
}
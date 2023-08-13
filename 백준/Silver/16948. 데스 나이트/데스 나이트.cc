// 12ms

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, r1, c1, r2, c2;
bool visited[201][201];

int dr[6] = {-2, -2, 0, 0, 2, 2};
int dc[6] = {-1, 1, -2, 2, -1, 1};

queue<tuple<int, int, int>> que;

void bfs()
{
    que.push({r1, c1, 0});
    visited[r1][c1] = 0;

    while (!que.empty())
    {
        int r = get<0>(que.front());
        int c = get<1>(que.front());
        int cnt = get<2>(que.front());

        que.pop();

        if (r == r2 && c == c2)
        {
            cout << cnt;
            return;
        }

        for (int d = 0; d < 6; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;

            if (!visited[nr][nc])
            {
                que.push({nr, nc, cnt+1});
                visited[nr][nc] = 1;
            }
        }
    }

    cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> r1 >> c1 >> r2 >> c2;    

    bfs();
}
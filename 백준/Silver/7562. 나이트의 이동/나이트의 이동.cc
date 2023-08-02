// 

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T;

int visited[301][301];

int dr[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
int dc[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int bfs(int n, int knight_r, int knight_c, int goal_r, int goal_c)
{
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> que;

    que.push({knight_r, knight_c});
    visited[knight_r][knight_c] = 1;

    int res = 0;

    while (!que.empty())
    {
        int r = que.front().first;
        int c = que.front().second;

        que.pop();

        if (r == goal_r && c == goal_c)
        {
            res = visited[r][c] - 1;
            break;
        }

        for (int d = 0; d < 8; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                continue;

            if (!visited[nr][nc])
            {
                que.push({nr, nc});
                visited[nr][nc] = visited[r][c] + 1;
            }
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    int l;
    int s1, s2, e1, e2;

    while (T--)
    {
        cin >> l >> s1 >> s2 >> e1 >> e2;

        cout << bfs(l, s1, s2, e1, e2) << '\n';
    }
}


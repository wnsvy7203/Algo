#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define INF 1000 * 100'000

using namespace std;

int T, K, W, H;
int board[1001][1001];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int visited[1001][1001];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pque;
void dijkstra(int a, int b)
{
    fill_n(&visited[0][0], 1001 * 1001, INF);
    pque.push({0, a, b});
    visited[a][b] = 0;

    int res = INF;

    while (!pque.empty())
    {
        int cost = get<0>(pque.top());
        int r = get<1>(pque.top());
        int c = get<2>(pque.top());
        pque.pop();

        if (r == 0 || r == H-1 || c == 0 || c == W-1)
            res = min(res, visited[r][c]);

        if (visited[r][c] < cost)
            continue;

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nc < 0 || nr >= H || nc >= W)
                continue;
            
            if (visited[nr][nc] > visited[r][c] + board[nr][nc])
            {
                visited[nr][nc] = visited[r][c] + board[nr][nc];
                pque.push({visited[nr][nc], nr, nc});
            }
        }
    }

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
    {
        vector<pair<char, int>> v;
        cin >> K >> W >> H;
        while (K--)
        {
            char c;
            int num;
            cin >> c >> num;
            v.push_back({c, num});
        }

        int y, x;

        for (int i = 0; i < H; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < W; j++)
            {
                if (str[j] == 'E')
                {
                    y = i;
                    x = j;
                }

                for (pair<char, int> p : v)
                    if (str[j] == p.first)
                        board[i][j] = p.second;
            }
        }

        dijkstra(y, x);
    }
}
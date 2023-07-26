// 

#include <iostream>
#include <stack>

using namespace std;

int N, M, R, G, B, T;
int RGB[1001][1001];
bool visited[1001][1001];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

stack<pair<int, int>> que;

void dfs(int i, int j)
{
    que.push({i, j});

    while (!que.empty())
    {
        int r = que.top().first;
        int c = que.top().second;

        que.pop();

        visited[r][c] = 1;

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;

            if (RGB[nr][nc] && !visited[nr][nc])
                que.push({nr, nc});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M*3; j++)
        {
            int num;

            cin >> num;

            RGB[i][j/3] += num;
        }
    }

    cin >> T;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (RGB[i][j] >= T*3)
                RGB[i][j] = 255;
            else
                RGB[i][j] = 0;
    
    int ans = 0;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (RGB[i][j] && !visited[i][j])
            {
                dfs(i, j);
                ans++;
            }

    cout << ans;
}
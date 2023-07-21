#include <iostream>
#include <stack>

using namespace std;

int T;
int H, W;
char grid[101][101];
bool visited[101][101];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

stack<pair<int, int>> stk;

void dfs(int i, int j)
{
    stk.push({i, j});

    while (!stk.empty())
    {
        int r = stk.top().first;
        int c = stk.top().second;
        visited[r][c] = 1;

        stk.pop();

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= H || nc < 0 || nc >= W)
                continue;
            
            if (grid[nr][nc] == '#' && !visited[nr][nc])
                stk.push({nr, nc});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> H >> W;
        
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                visited[i][j] = 0;

        for (int i = 0; i < H; i++)
        {
            string str;

            cin >> str;

            for (int j = 0; j < W; j++)
                grid[i][j] = str[j];
        }

        int cnt = 0;

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                if (grid[i][j] == '#' && !visited[i][j])
                {
                    dfs(i, j);
                    cnt++;
                }
        
        cout << cnt << '\n';
    }
}
//

#include <iostream>
#include <string>

using namespace std;

int R, C, K;
char board[5][5];
bool visited[5][5];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int ans = 0;

void dfs(int r, int c, int order)
{
    if (order == K)
    {
        if (r == 0 && c == C-1)
            ans++;

        return;
    }
    
    for (int d = 0; d < 4; d++)
    {
        int nr = r + dr[d];
        int nc = c + dc[d];

        if (nr < 0 || nr >= R || nc < 0 || nc >= C)
            continue;

        if (!visited[nr][nc] && board[nr][nc] == '.')
        {
            visited[nr][nc] = 1;
            dfs(nr, nc, order+1);
            visited[nr][nc] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> K;

    for (int i = 0; i < R; i++)
    {
        string str;

        cin >> str;

        for (int j = 0; j < C; j++)
            board[i][j] = str[j];
    }

    visited[R-1][0] = 1;
    dfs(R-1, 0, 1);

    cout << ans;
}
// 8ms

#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

int x, y;
int board[5][5];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool flag = 0;

void dfs(int r, int c, int apple, int cnt)
{
    board[r][c] = -1;

    if (apple == 2)
    {
        flag = 1;
        return;
    }

    for (int d = 0; d < 4; d++)
    {
        int nr = r + dr[d];
        int nc = c + dc[d];

        if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5)
            continue;
        
        if (board[nr][nc] == 0 && cnt <= 2)
        {
            dfs(nr, nc, apple, cnt+1);
            board[nr][nc] = 0;
        }
        else if (board[nr][nc] == 1 && cnt <= 2)
        {
            dfs(nr, nc, apple+1, cnt+1);
            board[nr][nc] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> board[i][j];

    cin >> x >> y;
    
    dfs(x, y, 0, 0);

    cout << flag;
}
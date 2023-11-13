#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

int R, C;
string str;
char board[20][20];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
bool visited[26];

int ans;
void dfs(int r, int c, int cnt)
{
    ans = max(ans, cnt);
    for (int d = 0; d < 4; d++)
    {
        int nr = r + dr[d];
        int nc = c + dc[d];

        if (nr < 0 || nr >= R || nc < 0 || nc >= C)
            continue;
        
        if (!visited[board[nr][nc]-65])
        {
            visited[board[nr][nc]-65] = 1;
            dfs(nr, nc, cnt+1);
            visited[board[nr][nc]-65] = 0;
        }
    }

    // stk.push({0, 0, 1});
    // visited[board[0][0]-65] = 1;

    // int res = 0;
    // while (!stk.empty())
    // {
    //     int r = get<0>(stk.top());
    //     int c = get<1>(stk.top());
    //     int cnt = get<2>(stk.top());
    //     stk.pop();

    //     res = max(res, cnt);

    //     for (int d = 0; d < 4; d++)
    //     {
    //         int nr = r + dr[d];
    //         int nc = c + dc[d];

    //         if (nr < 0 || nr >= R || nc < 0 || nc >= C)
    //             continue;
            
    //         if (!visited[board[nr][nc]-65])
    //         {
    //             visited[board[nr][nc]-65] = 1;
    //             stk.push({nr, nc, cnt+1});
    //         }
    //     }
    // }

    // return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        cin >> str;
        for (int j = 0; j < C; j++)
            board[i][j] = str[j];
    }
    
    visited[board[0][0]-65] = 1;
    dfs(0, 0, 1);
    cout << ans;
}
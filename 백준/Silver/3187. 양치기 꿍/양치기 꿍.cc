// 40ms

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int R, C;
char board[251][251];
bool visited[251][251];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

stack<pair<int, int>> stk;

pair<int, int> dfs(int x, int y, char b)
{
    stk.push({x, y});
    visited[x][y] = 1;

    int k = 0;
    int v = 0;

    if (b == 'k')
        k++;
    else if (b == 'v')
        v++;

    while (!stk.empty())
    {
        int r = stk.top().first;
        int c = stk.top().second;

        stk.pop();

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;
            
            if (board[nr][nc] != '#' && !visited[nr][nc])
            {
                stk.push({nr, nc});
                visited[nr][nc] = 1;

                if (board[nr][nc] == 'k')
                    k++;

                if (board[nr][nc] == 'v')
                    v++;
            }
        }
    }

    return {k, v};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    string str;
    
    for (int i = 0; i < R; i++)
    {
        cin >> str;

        for (int j = 0; j < C; j++)
            board[i][j] = str[j];
    }
        

    int cnt = 0;
    int sheep = 0;
    int wolf = 0;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (board[i][j] != '#' && !visited[i][j])
            {
                pair<int, int> tmp = dfs(i, j, board[i][j]);
                if (tmp.first > tmp.second)
                    sheep += tmp.first;
                else
                    wolf += tmp.second;
            }
    
    cout << sheep << ' ' << wolf;
}
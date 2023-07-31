// 24ms

#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int board[101][101];
int area[101];
bool visited[101][101];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

stack<pair<int, int>> stk;

void dfs(int x, int y, int h)
{
    stk.push({x, y});

    while (!stk.empty())
    {
        int r = stk.top().first;
        int c = stk.top().second;

        stk.pop();

        visited[r][c] = 1;

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;
            
            if (board[nr][nc] >= h && !visited[nr][nc])
                stk.push({nr, nc});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int bmax = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];

            bmax = max(bmax, board[i][j]);
        }

    for (int b = 0; b <= bmax; b++)
    {
        memset(visited, 0, sizeof(visited));

        int cnt = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (board[i][j] >= b && !visited[i][j])
                {
                    dfs(i, j, b);
                    cnt++;
                }
        
        area[b] = cnt;
    }
    
    cout << *max_element(area+1, area+bmax+1);
}
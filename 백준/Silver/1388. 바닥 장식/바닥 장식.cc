// 8ms

#include <iostream>
#include <stack>

using namespace std;

int N, M;
char board[51][51];

int dr[2] = {-1, 1};

int dc[2] = {-1, 1};

bool visited[51][51];
stack<pair<int, int>> stk;

void dfs(int i, int j)
{
    stk.push({i, j});
    visited[i][j] = 1;

    while (!stk.empty())
    {
        int r = stk.top().first;
        int c = stk.top().second;

        stk.pop();

        if (board[r][c] == '-')
        {
            for (int d = 0; d < 2; d++)
            {
                int nc = c + dc[d];

                if (nc < 0 || nc >= M)
                    continue;
                
                if (!visited[r][nc] && board[r][nc] == '-')
                {
                    stk.push({r, nc});
                    visited[r][nc] = 1;
                }
            }
        }
        else
        {
            for (int d = 0; d < 2; d++)
            {
                int nr = r + dr[d];

                if (nr < 0 || nr >= N)
                    continue;
                
                if (!visited[nr][c] && board[nr][c] == '|')
                {
                    stk.push({nr, c});
                    visited[nr][c] = 1;
                }
            }
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
        string str;

        cin >> str;
        
        for (int j = 0; j < M; j++)
            board[i][j] = str[j];
    }

    int cnt = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (!visited[i][j])
            {
                cnt++;
                dfs(i, j);
            }
    
    cout << cnt;
}
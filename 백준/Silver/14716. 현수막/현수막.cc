// 48ms

#include <iostream>
#include <stack>
#define MAX 1000001

using namespace std;

int M, N;
bool board[251][251];
bool visited[251][251];

int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

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
        
        for (int d = 0; d < 8; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= M || nc < 0 || nc >= N)
                continue;
            
            if (board[nr][nc] && !visited[nr][nc])
            {
                stk.push({nr, nc});
                visited[nr][nc] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    int cnt = 0;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] && !visited[i][j])
            {
                dfs(i, j);
                cnt++;
            }
    
    cout << cnt;
}
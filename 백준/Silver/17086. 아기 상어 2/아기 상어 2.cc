// 4ms

#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int grid[51][51];
bool visited[51][51];

int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};


int bfs(int x, int y)
{
    memset(visited, 0, sizeof(visited));
    queue<tuple<int, int, int>> que;
    que.push({x, y, 0});
    visited[x][y] = 1;

    int res = 0;

    while (!que.empty())
    {
        int r = get<0>(que.front());
        int c = get<1>(que.front());
        int cnt = get<2>(que.front());

        que.pop();

        if (grid[r][c])
        {
            res = cnt;
            break;
        }

        for (int d = 0; d < 8; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;
            
            if (!visited[nr][nc])
            {
                que.push({nr, nc, cnt+1});
                visited[nr][nc] = 1;   
            }
        }        
    }

    return res; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];
    
    int MAX = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            int tmp = bfs(i, j);

            MAX = max(MAX, tmp);
        }
                
    cout << MAX;
}
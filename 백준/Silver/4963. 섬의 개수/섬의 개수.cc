#include <iostream>
#include <stack>

using namespace std;

int w, h;
int map[51][51];
bool visited[51][51];
stack<pair<int, int>> stk;

int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void bfs(int i, int j)
{
    stk.push({i, j});
    
    while (!stk.empty())
    {
        int r = stk.top().first;
        int c = stk.top().second;

        stk.pop();
        visited[r][c] = 1;

        for (int d = 0; d < 8; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= h || nc < 0 || nc >= w)
                continue;
            
            if (map[nr][nc] && !visited[nr][nc])
                stk.push({nr, nc});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> w >> h;
        
        if (!w && !h)
            return 0;

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                visited[i][j] = 0;

        
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> map[i][j];

        int cnt = 0;
        
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (map[i][j] && !visited[i][j])
                {
                    bfs(i, j);
                    cnt++;
                }

        cout << cnt << '\n';
    }
}
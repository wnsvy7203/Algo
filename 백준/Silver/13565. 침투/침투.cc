#include <iostream>
#include <stack>

using namespace std;

int M, N;
int perc[1001][1001];
bool visited[1001][1001];

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

            if (nr < 0 || nr >= M || nc < 0 || nc >= N)
                continue;
            
            if (!perc[nr][nc] && !visited[nr][nc])
                stk.push({nr, nc});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    for (int i = 0; i < M; i++)
    {
        string str;

        cin >> str;

        for (int j = 0; j < N; j++)
            perc[i][j] = str[j] - 48;
    }

    for (int i = 0; i < N; i++)
        if (!perc[0][i] && !visited[0][i])
            dfs(0, i);
    
    bool flag = 0;
    for (int i = 0; i < N; i++)
        if (!perc[M-1][i] && visited[M-1][i])
            flag = 1;
    
    if (flag)
        cout << "YES";
    else
        cout << "NO";
}
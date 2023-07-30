// 16ms

#include <iostream>
#include <stack>

using namespace std;

int N, M, K;
int trash[101][101];
bool visited[101][101];

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

stack<pair<int, int>> stk;

int dfs(int x, int y)
{
    stk.push({x, y});

    int cnt = 0;

    while (!stk.empty())
    {
        int i = stk.top().first;
        int j = stk.top().second;

        stk.pop();

        for (int d = 0; d < 4; d++)
        {
            int ni = i + di[d];
            int nj = j + dj[d];

            if (ni <= 0 || ni > N || nj <= 0 || nj > M)
                continue;
            
            if (trash[ni][nj] && !visited[ni][nj])
            {
                cnt++;
                stk.push({ni, nj});
                visited[ni][nj] = 1;
            }
        }
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    int r, c;

    while (K--)
    {
        cin >> r >> c;

        trash[r][c] = 1;
    }

    int MAX = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (trash[i][j] && !visited[i][j])
                MAX = max(MAX, dfs(i, j));
    
    cout << MAX;
}
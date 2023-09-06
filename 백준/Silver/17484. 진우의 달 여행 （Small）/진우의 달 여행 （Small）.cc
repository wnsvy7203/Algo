//

#include <iostream>

using namespace std;

int N, M;
int board[6][6];
int dc[3] = {-1, 0, 1};
int visited[6];

int MIN = 600;

void dfs(int depth, int c, int dir)
{
    if (depth == N)
    {
        int sum = board[0][visited[0]];
        for (int i = 1; i < N; i++)
            sum += board[i][visited[i]];

        if (MIN > sum)
            MIN = sum;
        
        return;
    }

    for (int d = 0; d < 3; d++)
    {
        int nc = c + dc[d];

        if (nc < 0 || nc >= M)
            continue;
        
        if (dir != d)
        {
            visited[depth] = nc;
            dfs(depth+1, nc, d);
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < M; i++)
    {
        visited[0] = i;
        dfs(1, i, -1);
    }

    cout << MIN;
}
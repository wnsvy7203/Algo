#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, paper[100][100];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
bool visited[100][100];
vector<pair<int, int>> cheeze;

queue<pair<int, int>> que;
void bfs()
{
    fill_n(&visited[0][0], 100 * 100, false);

    que.push({0, 0});
    visited[0][0] = 1;

    while (!que.empty())
    {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;

            if (!visited[nr][nc] && !paper[nr][nc])
            {
                visited[nr][nc] = 1;
                que.push({nr, nc});
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (paper[i][j])
            {
                int cnt = 0;

                for (int d = 0; d < 4; d++)
                {
                    int nr = i + dr[d];
                    int nc = j + dc[d];

                    if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                        continue;
                    
                    if (visited[nr][nc])
                        cnt++;
                }

                if (cnt >= 2)
                    paper[i][j] = 0;
            }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> paper[i][j];
    
    // 모눈종이 가장자리는 치즈가 놓이지 않는다.
    // (0, 0)에서부터 계속 bfs 돌리면 되겠넹

    int ans = 0;
    while (1)
    {
        bool flag = 1;
        bfs();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (!visited[i][j] || paper[i][j])
                    flag = 0;

        if (flag)
        {
            cout << ans;
            break;
        }

        ans++;
    }
}
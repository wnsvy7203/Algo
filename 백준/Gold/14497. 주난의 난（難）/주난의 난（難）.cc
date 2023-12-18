#include <iostream>
#include <queue>
#include <tuple>

#define INF 300*300

using namespace std;

int N, M;
int X1, Y1, X2, Y2;
char board[301][301];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int ans;

void input()
{
    cin >> N >> M;
    cin >> X1 >> Y1 >> X2 >> Y2;
    for (int i = 1; i <= N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++)
            board[i][j+1] = str[j];
    }

}

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pque;
int dist[301][301];
void dijkstra()
{
    fill_n(&dist[0][0], 301*301, INF);
    dist[X1][Y1] = 0;
    pque.push({0, X1, Y1});

    while (!pque.empty())
    {
        int cost = get<0>(pque.top());
        int r = get<1>(pque.top());
        int c = get<2>(pque.top());
        pque.pop();

        if (dist[r][c] < cost)
            continue;
        
        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr <= 0 || nr > N || nc <= 0 || nc > M)
                continue;
            
            if (board[nr][nc] == '1' || board[nr][nc] == '#')
            {
                if (dist[nr][nc] > dist[r][c] + 1)
                {
                    dist[nr][nc] = dist[r][c] + 1;
                    pque.push({dist[nr][nc], nr, nc});
                }
            }
            else if (board[nr][nc] == '0')
            {
                if (dist[nr][nc] > dist[r][c])
                {
                    dist[nr][nc] = dist[r][c];
                    pque.push({dist[nr][nc], nr, nc});
                }
            }
        }
    }
}

bool visited[301][301];
queue<pair<int, int>> que;
void bfs()
{
    fill_n(&visited[0][0], 301*301, false);
    visited[X1][Y1] = 1;
    que.push({X1, Y1});

    while (!que.empty())
    {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr <= 0 || nr > N || nc <= 0 || nc > M)
                continue;
            
            if (!visited[nr][nc] && board[nr][nc] == '0')
            {
                visited[nr][nc] = 1;
                que.push({nr, nc});
            }
        }
    }
}

void jump()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (dist[i][j] == ans && (board[i][j] == '1' || board[i][j] == '#'))
                board[i][j] = '0';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    input();
    dijkstra();

    while (1)
    {
        bfs();
        if (visited[X2][Y2])
        {
            cout << ans;
            return 0;
        }
        ans++;
        jump();
    }
}
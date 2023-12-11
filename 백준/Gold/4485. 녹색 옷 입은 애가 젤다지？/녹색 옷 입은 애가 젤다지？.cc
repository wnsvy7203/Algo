#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define INF 125 * 125 * 10

using namespace std;

int N, board[125][125];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int visited[125][125];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pque;
void dijkstra()
{
    fill_n(&visited[0][0], 125*125, INF);
    pque.push({board[0][0], 0, 0});
    visited[0][0] = board[0][0];

    while (!pque.empty())
    {
        int cost = get<0>(pque.top());
        int r = get<1>(pque.top());
        int c = get<2>(pque.top());
        pque.pop();

        if (visited[r][c] < cost)
            continue;

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;

            if (visited[nr][nc] > cost + board[nr][nc])
            {
                visited[nr][nc] = cost + board[nr][nc];
                pque.push({visited[nr][nc], nr, nc});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int pro = 1;

    while (1)
    {
        cin >> N;
        if (!N)
            break;
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> board[i][j];

        dijkstra();

        cout << "Problem " << pro << ": " << visited[N-1][N-1] << '\n';
        pro++;
    }
}
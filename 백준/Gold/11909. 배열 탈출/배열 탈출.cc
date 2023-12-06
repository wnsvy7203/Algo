#include <iostream>
#include <queue>
#include <tuple>

#define INF 2222 * 2 * 222

using namespace std;

int n, A[2223][2223];
int dr[2] = {1, 0};
int dc[2] = {0, 1};

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pque;

int visited[2223][2223];
void dijkstra()
{
    fill_n(&visited[0][0], 2223*2223, INF);
    visited[1][1] = 0;
    pque.push({0, 1, 1});

    while (!pque.empty())
    {
        int cost = get<0>(pque.top());
        int r = get<1>(pque.top());
        int c = get<2>(pque.top());
        pque.pop();

        for (int d = 0; d < 2; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];
            int next_cost = cost;

            if (nr > n || nc > n)
                continue;

            if (A[nr][nc] >= A[r][c])
                next_cost += A[nr][nc] - A[r][c] + 1;
            
            if (next_cost >= visited[nr][nc])
                continue;
            
            visited[nr][nc] = next_cost;
            pque.push({next_cost, nr, nc}); 
        }
    }

    cout << visited[n][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> A[i][j];

    dijkstra();
}
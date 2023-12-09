#include <iostream>
#include <queue>
#include <tuple>

#define INF 50 * 50

using namespace std;

int n;
bool board[51][51];
string nums;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int visited[51][51];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pque;
void dijkstra()
{
    fill_n(&visited[0][0], 51*51, INF);
    pque.push({0, 1, 1});
    visited[1][1] = 0;

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

            if (nr <= 0 || nr > n || nc <= 0 || nc > n)
                continue;
            
            int next_cost = cost;          
            if (visited[nr][nc] > visited[r][c] + next_cost)
            {
                if (!board[nr][nc])
                    next_cost++;

                visited[nr][nc] = next_cost;
                pque.push({visited[nr][nc], nr, nc});
            }
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
    {
        cin >> nums;
        for (int j = 0; j < n; j++)
            if (nums[j] == '1')
                board[i][j+1] = 1;
            else
                board[i][j+1] = 0;
    }

    dijkstra();
}
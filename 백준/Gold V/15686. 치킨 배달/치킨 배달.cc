// 4ms

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, board[50][50];
bool visited[13];
vector<pair<int, int>> home, chicken, dist;

int ans = 2501;
int check_distance()
{
    int sum = 0;
    for (pair<int, int> p : home)
    {
        int r = p.first;
        int c = p.second;
        int d = 2501;

        for (int i = 0; i < dist.size(); i++)
        {
            int nr = dist[i].first;
            int nc = dist[i].second;
            int nd = abs(nr-r) + abs(nc-c);

            d = min(d, nd);
        }

        sum += d;
    }
    return sum;
}

void backtracking(int idx, int depth)
{
    if (depth == M)
    {
        ans = min(ans, check_distance());
        return;
    }

    for (int i = idx; i < chicken.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            dist.push_back(chicken[i]);

            backtracking(i, depth+1);

            visited[i] = 0;
            dist.pop_back();
        }
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                home.push_back({i, j});
            else if (board[i][j] == 2)
                chicken.push_back({i, j});
        }
    
    backtracking(0, 0);
    cout << ans;
}
// 
// idea: 집에서부터 구하는 게 나을지 치킨집에서부터 고르는 게 나을지 고민
// 우선 집에서부터 모든 치킨집까지의 거리를 구해서 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, board[50][50];
bool visited[13];
vector<pair<int, int>> home, chicken, v;

int ans = 2501;
int backtracking()
{
    int sum = 0;
    for (pair<int, int> p : home)
    {
        int r = p.first;
        int c = p.second;
        int dist = 2501;

        for (int i = 0; i < v.size(); i++)
        {
            int nr = v[i].first;
            int nc = v[i].second;
            int nd = abs(nr-r) + abs(nc-c);

            dist = min(dist, nd);
        }

        sum += dist;
    }
    return sum;
}

void close(int idx, int depth)
{
    if (depth == M)
    {
        ans = min(ans, backtracking());
        return;
    }

    for (int i = idx; i < chicken.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            v.push_back(chicken[i]);

            close(i, depth+1);

            visited[i] = 0;
            v.pop_back();
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
    
    close(0, 0);
    cout << ans;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int N, M;
int board[8][8];
int temp[8][8];
vector<pair<int, int>> v;
vector<pair<int, int>> comb;
vector<int> tmp;

queue<pair<int, int>> que;

int bfs()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            temp[i][j] = board[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (temp[i][j] == 2)
                que.push({i, j});
    
    for (int i = 0; i < comb.size(); i++)
        temp[comb[i].first][comb[i].second] = 1;
    
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
            
            if (!temp[nr][nc])
            {
                temp[nr][nc] = 2;
                que.push({nr, nc});
            }
        }
    }

    int res = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (!temp[i][j])
                res++;
    
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (!board[i][j])
                v.push_back({i, j});

    int len = v.size();
    for (int i = 0; i < len-3; i++)
        tmp.push_back(0);
    for (int i = 0; i < 3; i++)
        tmp.push_back(1);

    int ans = 0;
    do
    {
        comb.clear();
        for (int i = 0; i < len; i++)
            if (tmp[i])
                comb.push_back({v[i].first, v[i].second});
        
        ans = max(ans, bfs());

    } while (next_permutation(tmp.begin(), tmp.end()));
    cout << ans;
}
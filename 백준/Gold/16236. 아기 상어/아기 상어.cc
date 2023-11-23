// 8ms

#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M, board[20][20], dist[20][20];

int R, C, ans, cnt;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// bool compare(tuple<int, int, int> a, tuple<int, int, int> b)
// {
//     if (get<2>(a) == get<2>(b))
//     {
//         if (get<0>(a) == get<0>(b))
//             return get<1>(a) < get<1>(b);
//         return get<0>(a) < get<0>(b);
//     }

//     return get<2>(a) < get<2>(b);
// }

queue<pair<int, int>> que;
tuple<int, int, int> bfs(int y, int x, int weight)
{
    vector<tuple<int, int, int>> v;

    fill_n(&dist[0][0], 20*20, 0);
    dist[y][x] = 1;

    que.push({y, x});
    while (!que.empty())
    {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;
            
                // 아기 상어의 현재 크기와 같은 먹이는 지나갈 수는 있지만 먹을 수는 없다.
            if (!dist[nr][nc] && board[nr][nc] <= weight)
            {
                que.push({nr, nc});
                dist[nr][nc] = dist[r][c] + 1;

                // 아기 상어의 현재 크기보다 작은 것만 먹을 수 있다.
                // 먹을 수 있는 먹이의 위치 (nr, nc)와 현재 아기 상어의 위치에서부터의 거리를 tuple로 만들어 v에 담는다.
                // 거리를 1에서부터 시작했기 때문에, 거리는 -1 해서 넣어준다.
                if (board[nr][nc] && board[nr][nc] < weight)
                    v.push_back({dist[nr][nc]-1, nr, nc});
            }
        }
    }

    // v를 정렬하는데, 정렬 기준은 거리
    sort(v.begin(), v.end());
    if (v.empty())
        return {0, 0, 0};

    return v[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                // 아기 상어의 위치를 기억해둔다.
                R = i;
                C = j;
            }
        }
    
    int shark = 2;
    while (1)
    {
        // 아기 상어의 현재 위치에서 bfs
        tuple<int, int, int> res = bfs(R, C, shark);

        int far = get<0>(res);
        int NR = get<1>(res);
        int NC = get<2>(res);

        if (!NR && !NC && !far)
            break;

        ans += far;
        board[R][C] = 0;
        board[NR][NC] = 9;

        R = NR;
        C = NC;

        cnt++;
        if (cnt == shark)
        {
            shark++;
            cnt = 0;
        }
    }

    cout << ans;
}
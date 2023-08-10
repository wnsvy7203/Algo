// 8ms

#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <cstring>

using namespace std;

int T;
char r1, c1, r2, c2;

int dr[28] = {1, 1, -1, -1, 2, 2, -2, -2, 3, 3, -3, -3, 4, 4, -4, -4, 5, 5, -5, -5, 6, 6, -6, -6, 7, 7, -7, -7};
int dc[28] = {1, -1, 1, -1, 2, -2, 2, -2, 3, -3, 3, -3, 4, -4, 4, -4, 5, -5, 5, -5, 6, -6, 6, -6, 7, -7, 7, -7};

bool visited[8][8];

void bfs()
{
    memset(visited, 0, sizeof(visited));

    queue<tuple<pair<int, int>, string, int>> que;

    string str = "";
    str += r1;
    str += c1;
    
    que.push({make_pair(r1-65, c1-49), str, 0});
    visited[r1-65][c1-49] = 1;

    int ans1 = 0;
    string ans2 = "";
    bool flag = 0;

    while (!que.empty())
    {
        int r = get<0>(que.front()).first;
        int c = get<0>(que.front()).second;
        string visit = get<1>(que.front());
        int cnt = get<2>(que.front());

        if (r2-65 == r && c2-49 == c)
        {
            flag = 1;
            ans1 = cnt;
            ans2 = visit;
            break;
        }

        que.pop();

        for (int d = 0; d < 28; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= 8 || nc < 0 || nc >= 8)
                continue;
            
            if (!visited[nr][nc])
            {
                string tmp = visit;
                tmp += (char)(nr+65);
                tmp += (char)(nc+49);
                que.push({make_pair(nr, nc), tmp, cnt+1});
                visited[nr][nc] = 1;
            }
        }
    }

    if (flag)
    {
        cout << ans1 << ' ';

        for (int i = 0; i < ans2.size(); i++)
            cout << ans2[i] << ' ';
    }
    else
        cout << "Impossible";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> r1 >> c1 >> r2 >> c2;

        bfs();

        cout << '\n';
    }
}
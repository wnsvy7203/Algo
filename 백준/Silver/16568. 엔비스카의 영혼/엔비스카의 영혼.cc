// 108ms

#include <iostream>
#include <queue>
#define MAX 1000001

using namespace std;

int N, a, b;

bool visited[MAX];

queue<pair<int, int>> que;

void bfs()
{
    que.push({N, 0});
    visited[N] = 1;

    while (!que.empty())
    {
        int f = que.front().first;
        int cnt = que.front().second;
        que.pop();

        if (f == 0)
        {
            cout << cnt;
            return;
        }

        if (f-1 >= 0 && !visited[f-1])
        {
            que.push({f-1, cnt+1});
            visited[f-1] = 1;
        }

        if (f-1-a >= 0 && !visited[f-1-a])
        {
            que.push({f-1-a, cnt+1});
            visited[f-1-a] = 1;
        }

        if (f-1-b >= 0 && !visited[f-1-b])
        {
            que.push({f-1-b, cnt+1});
            visited[f-1-b] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> a >> b;    

    bfs();
}
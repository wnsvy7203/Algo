// 48ms

#include <iostream>
#include <queue>

using namespace std;

int A, B, N, M;
bool visited[100001];

queue<pair<int, int>> que;

void bfs(int n)
{
    que.push({n, 0});
    visited[n] = 1;

    int res = 0;

    while (!que.empty())
    {
        int f = que.front().first;
        int cnt = que.front().second;

        if (f == M)
        {
            res = cnt;
            break;
        }

        que.pop();

        if (f+1 <= 100000 && !visited[f+1])
        {
            que.push({f+1, cnt+1});
            visited[f+1] = 1;
        }

        if (f-1 >= 0 && !visited[f-1])
        {
            que.push({f-1, cnt+1});
            visited[f-1] = 1;
        }

        if (f+A <= 100000 && !visited[f+A])
        {
            que.push({f+A, cnt+1});
            visited[f+A] = 1;
        }

        if (f-A >= 0 && !visited[f-A])
        {
            que.push({f-A, cnt+1});
            visited[f-A] = 1;
        }

        if (f+B <= 100000 && !visited[f+B])
        {
            que.push({f+B, cnt+1});
            visited[f+B] = 1;
        }

        if (f-B >= 0 && !visited[f-B])
        {
            que.push({f-B, cnt+1});
            visited[f-B] = 1;
        }

        if (f*A <= 100000 && !visited[f*A])
        {
            que.push({f*A, cnt+1});
            visited[f*A] = 1;
        }

        if (f*B <= 100000 && !visited[f*B])
        {
            que.push({f*B, cnt+1});
            visited[f*B] = 1;
        }
    }

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> N >> M;

    bfs(N);
}
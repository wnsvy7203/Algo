#include <iostream>
#include <queue>

#define MAX 1000000001

using namespace std;

int A, B;
queue<pair<long long, int>> que;
int ans;

int dfs()
{
    que.push({A, 1});

    while (!que.empty())
    {
        long long f = que.front().first;
        int cnt = que.front().second;
        que.pop();

        if (f == B)
            return cnt;

        if (f*2 < MAX)
            que.push({f*2, cnt+1});

        if (f*10+1 < MAX)
            que.push({f*10+1, cnt+1});
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B;

    ans = dfs();
    cout << ans;
}
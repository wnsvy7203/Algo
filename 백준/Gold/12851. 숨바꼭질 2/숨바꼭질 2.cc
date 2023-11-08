#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 100001

using namespace std;

int N, K;
bool visited[MAX];
queue<pair<int, int>> que;

vector<int> ans;
int ans1 = 100001, ans2 = 0;

void bfs()
{
    que.push({N, 0});
    while (!que.empty())
    {
        int f = que.front().first;
        int cnt = que.front().second;
        que.pop();

        if (f == K)
        {
            ans1 = cnt;
            ans2++;
        }

        if (cnt > ans1)
            return;

        visited[f] = 1;

        if (f-1 >= 0 && !visited[f-1])
            que.push({f-1, cnt+1});

        if (f+1 < MAX && !visited[f+1])
            que.push({f+1, cnt+1});

        if (f*2 < MAX && !visited[f*2])
            que.push({f*2, cnt+1});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    bfs();
    cout << ans1 << '\n' << ans2;
}
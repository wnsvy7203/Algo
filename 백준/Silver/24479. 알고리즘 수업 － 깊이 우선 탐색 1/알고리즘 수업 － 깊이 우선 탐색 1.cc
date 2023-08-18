// 8ms

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

int N, M, R;
vector<int> E[MAX];
int visited[MAX];

int cnt = 0;

void dfs(int r)
{
    cnt++;
    visited[r] = cnt;

    for (int x : E[r])
        if (!visited[x])
            dfs(x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> R;
    
    int u, v;
    while (M--)
    {
        cin >> u >> v;

        E[u].push_back(v);
        E[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
        sort(E[i].begin(), E[i].end());

    dfs(R);
    
    for (int i = 1; i <= N; i++)
        cout << visited[i] << '\n';
}
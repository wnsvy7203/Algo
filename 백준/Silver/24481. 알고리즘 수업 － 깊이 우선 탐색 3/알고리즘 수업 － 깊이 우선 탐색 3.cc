// 96ms

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

int N, M, R;
vector<int> E[MAX];
int visited[MAX];

void dfs(int r, int depth)
{
    visited[r] = depth;

    for (int x : E[r])
        if (!visited[x])
            dfs(x, depth+1);
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

    dfs(R, 1);
    
    for (int i = 1; i <= N; i++)
        cout << visited[i]-1 << '\n';
}
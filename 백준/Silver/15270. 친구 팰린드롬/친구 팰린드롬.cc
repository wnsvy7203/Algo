// 8ms

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> graph[21];
bool visited[21];

int dfs(int n, int cnt)
{
    if (n > N)
        return cnt;
    
    if (visited[n])
        return dfs(n+1, cnt);

    int res = 0;
    for (int i : graph[n])
        if (!visited[i])
        {
            visited[i] = 1;
            res = max(res, dfs(n+1, cnt+1));
            visited[i] = 0;
        }
    
    return max(res, dfs(n+1, cnt));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    int u, v;
    while (M--)
    {
        cin >> u >> v;

        if (u > v)
            swap(u, v);

        graph[u].push_back(v);
    }

    int res = dfs(1, 0) * 2;
    res = N > res ? res+1 : res;
    
    cout << res;
}
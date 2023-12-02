#include <iostream>
#include <vector>
#include <queue>

#define INF 30 * 100 + 1

using namespace std;

int n, m, r;
int t[101];
vector<pair<int, int>> graph[101];

int dijkstra(int idx)
{
    int dist[101];
    fill_n(&dist[1], 100, INF);
    dist[idx] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    pque.push({0, idx});

    while (!pque.empty())
    {
        int cost = pque.top().first;
        int node = pque.top().second;
        pque.pop();

        if (dist[node] < cost)
            continue;

        for (pair<int, int> p : graph[node])
        {
            int next_cost = p.first;
            int next_node = p.second;

            if (dist[next_node] > cost + next_cost)
            {
                dist[next_node] = cost + next_cost;
                pque.push({dist[next_node], next_node});
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        if (dist[i] <= m)
            res += t[i];
    
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    
    while (r--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dijkstra(i));
    
    cout << ans;
}
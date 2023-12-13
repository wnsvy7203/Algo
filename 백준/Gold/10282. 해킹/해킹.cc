#include <iostream>
#include <vector>
#include <queue>

#define INF 1000 * 100'000

using namespace std;

int T, n, d, c;

int visited[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
void dijkstra(vector<pair<int, int>> v[])
{
    fill_n(&visited[1], 10000, INF);
    pque.push({0, c});
    visited[c] = 0;

    while (!pque.empty())
    {
        int cost = pque.top().first;
        int node = pque.top().second;
        pque.pop();

        if (visited[node] < cost)
            continue;
        
        for (int i = 0; i < v[node].size(); i++)
        {
            int next_cost = v[node][i].first;
            int next_node = v[node][i].second;

            if (visited[next_node] > cost + next_cost)
            {
                visited[next_node] = cost + next_cost;
                pque.push({visited[next_node], next_node});
            }
        }
    }

    int cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++)
        if (visited[i] != INF)
        {
            cnt++;
            ans = max(ans, visited[i]);
        }

    cout << cnt << ' ' << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
    {
        vector<pair<int, int>> graph[10001];
        cin >> n >> d >> c;
        while (d--)
        {
            int a, b, s;
            cin >> a >> b >> s;
            graph[b].push_back({s, a});
        }

        dijkstra(graph);
    }
}
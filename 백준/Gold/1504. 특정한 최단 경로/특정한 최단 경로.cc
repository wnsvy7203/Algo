#include <iostream>
#include <vector>
#include <queue>

#define INF 800 * 1000 + 1

using namespace std;

int N, E, v1, v2;
vector<pair<int, int>> graph[801];

int dist[801];
pair<int, bool> dijkstra(int s, int e)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    fill_n(&dist[1], 800, INF);
    pque.push({0, s});
    dist[s] = 0;
    bool flag = 1;

    while (!pque.empty())
    {
        int cost = pque.top().first;
        int node = pque.top().second;
        pque.pop();

        if (dist[node] < cost)
            continue;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int next_cost = graph[node][i].first;
            int next_node = graph[node][i].second;

            if (dist[next_node] > cost + next_cost)
            {
                dist[next_node] = cost + next_cost;
                pque.push({dist[next_node], next_node});
            }
        }
    }

    if (dist[e] == INF)
        flag = 0;

    return {dist[e], flag};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> E;
    while (E--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
    cin >> v1 >> v2;

    pair<int, bool> one_to_v1 = dijkstra(1, v1);
    pair<int, bool> one_to_v2 = dijkstra(1, v2);
    pair<int, bool> v1_to_v2 = dijkstra(v1, v2);
    pair<int, bool> v1_to_N = dijkstra(v1, N);
    pair<int, bool> v2_to_N = dijkstra(v2, N);

    bool flag1 = 1;
    bool flag2 = 1;

    int route1 = one_to_v1.first + v1_to_v2.first + v2_to_N.first;
    int route2 = one_to_v2.first + v1_to_v2.first + v1_to_N.first;

    if (!one_to_v1.second || !v1_to_v2.second || !v2_to_N.second)
        flag1 = 0;
    
    if (!one_to_v2.second || !v1_to_v2.second || !v1_to_N.second)
        flag2 = 0;
    
    if (flag1 && flag2)
        cout << min(route1, route2);
    else if (flag1)
        cout << route1;
    else if (flag2)
        cout << route2;
    else
        cout << -1;
}
#include <iostream>
#include <vector>
#include <queue>

#define INF 100'001

using namespace std;

int N, M, X;
vector<pair<int, int>> graph[1001];
int dist[1001];         // X에서의 거리
int dist_go[1001];      // X까지의 거리

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
void dijkstra()
{
    fill_n(&dist[1], 1000, INF);
    pque.push({0, X});
    dist[X] = 0;

    while (!pque.empty())
    {
        int cost = pque.top().first;
        int node = pque.top().second;
        pque.pop();

        if (dist[node] < cost)
            continue;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int next_node = graph[node][i].first;
            int next_cost = graph[node][i].second;

            if (dist[next_node] > cost + next_cost)
            {
                dist[next_node] = cost + next_cost;
                pque.push({dist[next_node], next_node});
            }
        }
    }
}

int dijkstra_go(int idx)
{
    int tmp[1001];
    fill_n(&tmp[1], 1000, INF);
    pque.push({0, idx});
    tmp[idx] = 0;

    while (!pque.empty())
    {
        int cost = pque.top().first;
        int node = pque.top().second;
        pque.pop();

        if (tmp[node] < cost)
            continue;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int next_node = graph[node][i].first;
            int next_cost = graph[node][i].second;

            if (tmp[next_node] > cost + next_cost)
            {
                tmp[next_node] = cost + next_cost;
                pque.push({tmp[next_node], next_node});
            }
        }
    }

    return tmp[X];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> X;
    while (M--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    dijkstra();
    for (int i = 1; i <= N; i++)
        dist_go[i] = dijkstra_go(i);
    
    int ans = 0;
    for (int i = 1; i <= N; i++)
        if (dist[i] != INF && dist_go[i])
            ans = max(ans, dist[i] + dist_go[i]);
    
    cout << ans;
}
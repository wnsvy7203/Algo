#include <iostream>
#include <vector>
#include <queue>

#define INF 45 * 1000

using namespace std;

int N, M, A, B, C;
int ans = INF;
vector<pair<int, int>> graph[11];

bool visited[11];
int dist[11];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
void dijkstra()
{
    fill_n(&dist[1], 10, INF);
    pque.push({0, A});
    dist[A] = 0;

    while (!pque.empty())
    {
        int cost = pque.top().first;
        int node = pque.top().second;
        pque.pop();

        if (dist[node] < cost || visited[node] > C)
            continue;
        
        for (int i = 0; i < graph[node].size(); i++)
        {
            int next_cost = graph[node][i].first;
            int next_node = graph[node][i].second;

            if (dist[next_node] > C && dist[next_node] > cost + next_cost)
            {
                dist[next_node] = cost + next_cost;
                pque.push({dist[next_node], next_node});
            }
        }
    }
}

void dfs(int node, int max_cost, int cost_sum)
{
    if (cost_sum > C)
        return;
    
    if (node == B)
    {
        ans = min(ans, max_cost);
        return;
    }

    for (int i = 0; i < graph[node].size(); i++)
    {
        int next_node = graph[node][i].second;

        if (!visited[next_node])
        {
            int next_maxCost = max(max_cost, graph[node][i].first);
            int next_cost = cost_sum + graph[node][i].first;
            
            visited[next_node] = 1;
            dfs(next_node, next_maxCost, next_cost);
            visited[next_node] = 0;
        }
    }
}

void backtracking()
{
    visited[A] = 1;
    dfs(A, 0, 0);

    if (ans == INF)
        cout << -1;
    else
        cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> A >> B >> C;
    while (M--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    dijkstra();
    backtracking();
}
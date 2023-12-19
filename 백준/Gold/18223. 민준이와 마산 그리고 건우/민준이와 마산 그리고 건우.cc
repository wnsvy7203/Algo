#include <iostream>
#include <vector>
#include <queue>

#define INF 10000 * 10000

using namespace std;

int V, E, P;

vector<pair<int, int>> graph[5001];
void input()
{
    cin >> V >> E >> P;
    while (E--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
}

int dist[5001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pque;
void dijkstra()
{
    fill_n(&dist[1], 5000, INF);
    dist[1] = 0;
    pque.push({0, 1});

    while (!pque.empty())
    {
        int cost = pque.top().first;
        int node = pque.top().second;
        pque.pop();

        if (dist[node] < cost)
            continue;

        for (auto i : graph[node])
        {
            int next_cost = i.first;
            int next_node = i.second;

            if (dist[next_node] > cost + next_cost)
            {
                dist[next_node] = cost + next_cost;
                pque.push({dist[next_node], next_node});
            }
        }
    }
}

int visited[5001];
void dfs(int num)
{
    visited[num] = 1;

    for (auto i : graph[num])
    {
        int cost = i.first;
        int node = i.second;

        if (dist[num] - cost == dist[node])
        dfs(node);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    dijkstra();
    dfs(V);
    if (visited[P])
        cout << "SAVE HIM";
    else
        cout << "GOOD BYE";
}
#include <iostream>
#include <vector>
#include <queue>

#define INF 100'000 * 100

using namespace std;

int n, m, s, t;
vector<pair<int, int>> graph[5001];

int visited[5001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
void dijkstra()
{
    fill_n(&visited[1], 5000, INF);
    pque.push({0, s});
    visited[s] = 0;

    while (!pque.empty())
    {
        int cost = pque.top().first;
        int node = pque.top().second;
        pque.pop();

        if (visited[node] < cost)
            continue;
        
        for (int i = 0; i < graph[node].size(); i++)
        {
            int next_cost = graph[node][i].first;
            int next_node = graph[node][i].second;

            if (visited[next_node] > cost + next_cost)
            {
                visited[next_node] = cost + next_cost;
                pque.push({visited[next_node], next_node});
            }
        }
    }

    cout << visited[t];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    cin >> s >> t;

    dijkstra();
}
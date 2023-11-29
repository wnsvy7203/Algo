#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define INF 100'000'001

using namespace std;

int n, m, A, B;
vector<pair<int, int>> graph[1001];
int dist[1001];

int par[1001];
stack<int> route;


void dijkstra()
{
    fill_n(&dist[1], 1000, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({0, A});
    dist[A] = 0;

    while (!que.empty())
    {
        int cost = que.top().first;
        int node = que.top().second;
        que.pop();

        if (dist[node] < cost)
            continue;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int next_node = graph[node][i].first;
            int next_cost = graph[node][i].second;

            if (dist[next_node] > cost + next_cost)
            {
                par[next_node] = node;
                dist[next_node] = cost + next_cost;
                que.push({dist[next_node], next_node});
            }
        }
    }

    int node = B;
    while (node)
    {
        route.push(node);
        node = par[node];
    }

    cout << dist[B] << '\n';
    cout << route.size() << '\n';
    while (!route.empty())
    {
        cout << route.top() << ' ';
        route.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    cin >> A >> B;

    dijkstra();
}
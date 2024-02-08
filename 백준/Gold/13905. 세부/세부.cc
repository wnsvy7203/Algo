#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

int N, M, s, e;
vector<pair<int, int>> graph[100001];

int dist[100001];
bool visited[100001];
priority_queue<pair<int, int>> pq;
void dijkstra()
{
    pq.push({INF, s});
    dist[s] = INF;

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = 1;

        for (pair<int, int> edge : graph[node])
        {
            int next_cost = min(cost, edge.first);
            int next_node = edge.second;

            if (dist[next_node] < next_cost)
            {
                dist[next_node] = next_cost;
                pq.push({next_cost, next_node});
            }
        }
    }
}

void init()
{
    cin >> N >> M >> s >> e;
    while (M--)
    {
        int h1, h2, k;
        cin >> h1 >> h2 >> k;
        graph[h1].push_back({k, h2});
        graph[h2].push_back({k, h1});
    }
}

void find_answer()
{
    cout << dist[e];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    dijkstra();
    find_answer();
}
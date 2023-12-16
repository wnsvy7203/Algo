#include <iostream>
#include <vector>
#include <queue>

#define INF 10000 * 1000

using namespace std;

int N, V, E, A, B;
vector<int> KIST;
vector<pair<int, int>> graph[1001];

int dist[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;

void input()
{
    cin >> N >> V >> E;
    cin >> A >> B;
    KIST.push_back(0);
    for (int i = 1; i <= N; i++)
    {
        int H;
        cin >> H;
        KIST.push_back(H);
    }

    while (E--)
    {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({l, b});
        graph[b].push_back({l, a});
    }
}

int dijkstra(int start)
{
    fill_n(&dist[1], 1000, INF);
    pque.push({0, start});
    dist[start] = 0;

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

    int res = 0;
    if (dist[A] == INF)
        res -= 1;
    else
        res += dist[A];
    
    if (dist[B] == INF)
        res -= 1;
    else
        res += dist[B];
    
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans += dijkstra(KIST[i]);

    cout << ans;
}
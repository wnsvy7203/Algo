#include <iostream>
#include <vector>
#include <queue>

#define MAX 100'000
#define INF 10'000'000'000

using namespace std;

int N, M;
bool pos[MAX];
vector<pair<int, int>> graph[MAX];

long long visited[MAX];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pque;
void dijkstra()
{
    fill_n(&visited[0], MAX, INF);
    pque.push({0, 0});
    visited[0] = 0;

    while (!pque.empty())
    {
        long long cost = pque.top().first;
        int node = pque.top().second;
        pque.pop();

        if (visited[node] < cost)
            continue;
        
        if (node != N-1 && pos[node])
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

    if (visited[N-1] == INF)
        cout << -1;
    else
        cout << visited[N-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> pos[i];
    
    while (M--)
    {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({t, b});
        graph[b].push_back({t, a});
    }

    dijkstra();
}
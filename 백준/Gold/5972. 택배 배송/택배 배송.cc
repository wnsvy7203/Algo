#include <iostream>
#include <vector>
#include <queue>

#define INF 50000 * 1000

using namespace std;

int N, M;
vector<pair<int, int>> graph[50001];
int visited[50001];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
void dijkstra()
{
    fill_n(&visited[1], 50000, INF);
    pque.push({0, 1});
    visited[1] = 0;

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

    cout << visited[N];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    while (M--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({C, B});
        graph[B].push_back({C, A});
    }

    dijkstra();
}
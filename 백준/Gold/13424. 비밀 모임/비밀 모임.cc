#include <iostream>
#include <vector>
#include <queue>

#define INF 1000 * 100 * 99 / 2

using namespace std;

int T, N, M, K;
vector<pair<int, int>> graph[101];
vector<int> loc;

int dist[101][101];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
void dijkstra(int idx)
{
    for (int i = 1; i <= N; i++)
        dist[idx][i] = INF;

    int start = loc[idx];
    dist[idx][start] = 0;
    pque.push({0, start});

    while (!pque.empty())
    {
        int cost = pque.top().first;
        int node = pque.top().second;
        pque.pop();

        if (dist[idx][node] < cost)
            continue;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int next_cost = graph[node][i].first;
            int next_node = graph[node][i].second;

            if (dist[idx][next_node] > cost + next_cost)
            {
                dist[idx][next_node] = cost + next_cost;
                pque.push({dist[idx][next_node], next_node});
            }
        }
    }
}

void input()
{
    cin >> N >> M;
    while (M--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    cin >> K;
    loc.push_back(0);
    for (int i = 1; i <= K; i++)
    {
        int num;
        cin >> num;
        loc.push_back(num);
    }
}

void find_answer()
{
    int res = INF;
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= K; j++)
            sum += dist[j][i];
        
        if (res > sum)
        {
            res = sum;
            ans = i;
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
    {
        for (int i = 1; i < 101; i++)
            graph[i].clear();
        loc.clear();
        
        input();

        for (int i = 1; i <= K; i++)
            dijkstra(i);
        
        find_answer();
    }
}
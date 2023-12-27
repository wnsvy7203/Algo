#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 100'000 * 10'000

using namespace std;

int N, M, X, Y;
vector<pair<int, int>> graph[1000];

void input()
{
    cin >> N >> M >> X >> Y;
    while (M--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({C, B});
        graph[B].push_back({C, A});
    }
}

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pque;
int dist[1000];
void dijkstra()
{
    fill_n(&dist[0], 1000, INF);
    dist[Y] = 0;
    pque.push({0, Y});

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
}

vector<int> dist_v;
void find_answer()
{
    bool flag = 1;
    for (int i = 0; i < N; i++)
    {
        if (dist[i] * 2 > X || dist[i] == INF)
        {
            flag = 0;
            break;
        }

        if (dist[i])
            dist_v.push_back(dist[i] * 2);
    }    

    if (flag)
    {
        int ans = 0;
        int idx = 0;
        sort(dist_v.begin(), dist_v.end());
        while (1)
        {
            ans++;
            int time = X;

            while (1)
            {
                if (time < dist_v[idx])
                    break;
                
                time -= dist_v[idx++];
                if (idx == dist_v.size())
                    break;
            }

            if (idx == dist_v.size())
                break;
        }

        cout << ans;
    }
    else
        cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    dijkstra();
    find_answer();
}
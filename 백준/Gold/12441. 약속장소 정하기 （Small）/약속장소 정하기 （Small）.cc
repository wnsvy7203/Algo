#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 10 * 200 * 110 * 200

using namespace std;

int T, N, P, M, y;
int visited[11][111];
vector<pair<int, int>> friend_info;
vector<pair<int, int>> graph[111];

void initialize()
{
    friend_info.clear();
    for (int i = 0; i <= N; i++)
        graph[i].clear();

    for (int i = 0; i < P; i++)
        for (int j = 0; j <= N; j++)
            visited[i][j] = INF;
    y = INF;
}

void input()
{
    cin >> N >> P >> M;
    initialize();

    for (int i = 0; i < P; i++)
    {
        int X, V;
        cin >> X >> V;
        friend_info.push_back({X, V});
    }

    for (int i = 0; i < M; i++)
    {
        int D, L;
        cin >> D >> L;
        vector<int> tmp;
        for (int j = 0; j < L; j++)
        {
            int city;
            cin >> city;
            tmp.push_back(city);
        }

        for (int j = 0; j < L-1; j++)
        {
            graph[tmp[j]].push_back({D, tmp[j+1]});
            graph[tmp[j+1]].push_back({D, tmp[j]});
        }
    }
}

void dijkstra(int idx)
{
    int start = friend_info[idx].first;
    int time = friend_info[idx].second;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    visited[idx][start] = 0;
    pque.push({0, start});

    while (!pque.empty())
    {
        int cost = pque.top().first;
        int node = pque.top().second;
        pque.pop();

        if (visited[idx][node] < cost)
            continue;
        
        for (int i = 0; i < graph[node].size(); i++)
        {
            int next_cost = graph[node][i].first * time;
            int next_node = graph[node][i].second;

            if (visited[idx][next_node] > cost + next_cost)
            {
                visited[idx][next_node] = cost + next_cost;
                pque.push({visited[idx][next_node], next_node});
            }
        }
    }
}

void find_answer()
{
    for (int i = 1; i <= N; i++)
    {
        bool flag = 1;
        int tmp = 0;
        for (int j = 0; j < P; j++)
        {
            if (visited[j][i] == INF)
            {
                flag = 0;
                break;
            }
            tmp = max(tmp, visited[j][i]);
        }

        if (flag)
            y = min(y, tmp);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int x = 1; x <= T; x++)
    {
        input();
        
        for (int i = 0; i < P; i++)
            dijkstra(i);
        
        find_answer();

        if (y == INF)
            cout << "Case #" << x << ": -1\n";
        else
            cout << "Case #" << x << ": " << y << '\n';
    }
}
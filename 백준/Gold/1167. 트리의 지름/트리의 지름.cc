#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define MAX 100001

using namespace std;

int V;
int dist[MAX];
vector<pair<int, int>> graph[MAX];

stack<pair<int, int>> stk;
int diameter(int s)
{
    fill_n(&dist[0], MAX, 0);
    stk.push({s, 0});
    dist[s] = 1;

    while (!stk.empty())
    {
        int node = stk.top().first;
        int far = stk.top().second;
        stk.pop();

        for (pair<int, int> p : graph[node])
            if (!dist[p.first])
            {
                dist[p.first] = dist[node] + p.second;
                stk.push({p.first, far + p.second});
            }
    }

    return *max_element(dist+1, dist+V+1)-1;
}

int dfs()
{
    stk.push({1, 0});
    dist[1] = 1;

    while (!stk.empty())
    {
        int node = stk.top().first;
        int far = stk.top().second;
        stk.pop();

        for (pair<int, int> p : graph[node])
            if (!dist[p.first])
            {
                dist[p.first] = dist[node] + p.second;
                stk.push({p.first, far + p.second});
            }
    }

    int res = 0; int m = 0;
    for (int i = 2; i <= V; i++)
        if (m < dist[i])
        {
            m = dist[i];
            res = i;
        }
    
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V;
    for (int i = 0; i < V; i++)
    {
        int u, v, w;
        cin >> u;

        while (1)
        {
            cin >> v;
            if (v == -1)
                break;

            cin >> w;
            graph[u].push_back({v, w});
        }
    }

    for (int i = 1; i <= V; i++)
        sort(graph[i].begin(), graph[i].end());
    
    cout << diameter(dfs());
}
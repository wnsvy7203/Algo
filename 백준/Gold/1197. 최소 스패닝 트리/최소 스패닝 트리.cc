#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int V, E, ans;
int par[10001];
vector<tuple<int, int, int>> edges;

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void uf(int x, int y)
{
    x = find(x);
    y = find(y);
    par[y] = x;
}

void init()
{
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        edges.push_back({cost, from, to});
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= V; i++)
        par[i] = i;
}

void kruskal()
{
    for (int i = 0; i < edges.size(); i++)
    {
        if (find(get<1>(edges[i])) != find(get<2>(edges[i])))
        {
            uf(get<1>(edges[i]), get<2>(edges[i]));
            ans += get<0>(edges[i]);
        }
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    init();
    kruskal();
}
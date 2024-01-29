#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX 500001

using namespace std;

int n, m, ans;
int par[MAX];
vector<pair<int, int>> graph;

// 특정 정점의 부모를 찾는 함수
int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

// 두 정점을 하나의 집합으로 합치는 함수
void union_sets(int x, int y)
{
    x = find(x);
    y = find(y);
    par[y] = x;
}

void init()
{
    cin >> n >> m;
    // 정점의 부모를 자기 자신으로 초기화
    for (int i = 1; i < n; i++)
        par[i] = i;
    
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph.push_back({u, v});
    }
}

void find_answer()
{
    for (int i = 0; i < m; i++)
    {
        int u = graph[i].first;
        int v = graph[i].second;

        if (find(u) == find(v))
        {
            ans = i+1;
            break;
        }

        union_sets(u, v);
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    init();
    find_answer();
}
// 

#include <iostream>
#include <vector>

#define MAX 500001

using namespace std;

int N;
vector<int> graph[MAX];
bool visited[MAX];

int cnt = 0;
void dfs(int r, int depth)
{
    if (graph[r].size() == 1 && r != 1)
    {
        cnt += depth;
        return;
    }

    for (int x : graph[r])
        if (!visited[x])
        {
            visited[x] = 1;
            dfs(x, depth+1);
            visited[x] = 0;
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int M = N-1;

    int u, v;
    while (M--)
    {
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    visited[1] = 1;
    dfs(1, 0);
    
    if (cnt % 2)
        cout << "Yes";
    else
        cout << "No";
}
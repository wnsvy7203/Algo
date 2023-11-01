//

#include <iostream>
#include <vector>
#include <stack>

#define MAX 100001

using namespace std;

int N;
int par[MAX];
bool visited[MAX];
vector<int> graph[MAX];
stack<int> stk;

void dfs()
{
    stk.push(1);
    visited[1] = 1;

    while (!stk.empty())
    {
        int t = stk.top();
        stk.pop();

        for (int n : graph[t])
            if (!visited[n])
            {
                stk.push(n);
                visited[n] = 1;
            }
            else
                par[t] = n;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N-1; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs();

    for (int i = 2; i <= N; i++)
        cout << par[i] << '\n';
}
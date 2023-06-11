// Silver 2. the Count of Linked Nodes

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> graph[1001];
int visited[1001];
int N, M;
stack<int> stk;

void dfs(int v)
{
    stk.push(v);

    while (!stk.empty())
    {
        int top = stk.top();
        visited[top] = 1;
        stk.pop();

        for (int i = 0; i < graph[top].size(); i++)
            if (!visited[graph[top][i]])
                stk.push(graph[top][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int u, v;
    int cnt = 0;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
        if (!visited[i])
        {
            cnt++;
            dfs(i);
        }
    
    cout << cnt;
}
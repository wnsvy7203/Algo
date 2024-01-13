#include <iostream>

using namespace std;

int N, K;
int graph[10][10];
bool visited[10];

void input()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];
    
    visited[K] = 1;
}

void floyd()
{
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int ans = INT32_MAX;
void backtracking(int idx, int cost, int cnt)
{
    if (ans < cost)
        return;
    
    if (cnt == N)
    {
        ans = min(ans, cost);
        return;
    }

    for (int i = 0; i < N; i++)
        if (!visited[i])
        {
            visited[i] = 1;
            backtracking(i, cost + graph[idx][i], cnt+1);
            visited[i] = 0;
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    floyd();
    backtracking(K, 0, 1);

    cout << ans;
}
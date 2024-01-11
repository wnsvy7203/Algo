#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int n, m, k;
int graph[251][251];

void input()
{
    cin >> n >> m;

    // init
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;

            graph[i][j] = INF;
        }

    while (m--)
    {
        int u, v, b;
        cin >> u >> v >> b;

        graph[u][v] = 0;
        // b가 1이면 양방향 길이므로 거꾸로도 비용이 0
        if (b)
            graph[v][u] = 0;
        // b가 0이면 단방향 길이므로 못 가는 길은 비용 1
        else
            graph[v][u] = 1;
    }
}

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

void find_answer()
{
    cin >> k;
    while (k--)
    {
        int s, e;
        cin >> s >> e;
        cout << graph[s][e] << '\n';
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    floyd();
    find_answer();
}
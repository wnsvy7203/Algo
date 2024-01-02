#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int V, E;
int graph[401][401];

void input()
{
    cin >> V >> E;
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            graph[i][j] = INF;

    while (E--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
}


void floyd()
{
    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

void find_answer()
{
    int ans = INF;
    for (int i = 1; i <= V; i++)
        ans = min(ans, graph[i][i]);
    
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    floyd();
    find_answer();
}
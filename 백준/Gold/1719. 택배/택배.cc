#include <iostream>

#define INF 1e9

using namespace std;

int n, m;
int graph[201][201];
int first_visited[201][201];

void input()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            
            graph[i][j] = INF;
        }

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u][v] = w;
        first_visited[u][v] = v;

        graph[v][u] = w;
        first_visited[v][u] = u;
    }
}

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    first_visited[i][j] = first_visited[i][k];
                }
}

void find_answer()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                cout << "- ";
            else
                cout << first_visited[i][j] << ' ';
        }

        cout << '\n';
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
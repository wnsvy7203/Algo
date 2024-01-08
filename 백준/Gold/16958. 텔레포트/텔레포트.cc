// 948ms

#include <iostream>

#define INF 1e9

using namespace std;

int N, T, M;
int v[1001][3];
int graph[1001][1001];

int dist(int a[3], int b[3])
{
    return abs(a[1] - b[1]) + abs(a[2] - b[2]);
}

void floyd()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;

            graph[i][j] = INF;
        }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;

            graph[i][j] = dist(v[i], v[j]);
            
            if (v[i][0] && v[j][0])
                graph[i][j] = min(graph[i][j], T);
        }
    
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> T;
    for (int i = 0; i < N; i++)
        cin >> v[i][0] >> v[i][1] >> v[i][2];

    floyd();

    cin >> M;
    while (M--)
    {
        int A, B;
        cin >> A >> B;
        cout << graph[A-1][B-1] << '\n';
    }
}
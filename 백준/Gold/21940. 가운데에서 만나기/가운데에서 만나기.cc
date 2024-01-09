#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

int N, M, K;
int graph[201][201];
int home[201];

void input()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                continue;
            
            graph[i][j] = INF;
        }

    while (M--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A][B] = C;
    }

    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        int C;
        cin >> C;
        home[i] = C;
    }
}

void floyd()
{
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

}

void find_answer()
{
    int res = INF;
    for (int i = 1; i <= N; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= K; j++)
            tmp = max(tmp, graph[i][home[j]] + graph[home[j]][i]);
        
        res = min(res, tmp);
    }

    for (int i = 1; i <= N; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= K; j++)
            tmp = max(tmp, graph[i][home[j]] + graph[home[j]][i]);

        if (tmp == res)
            cout << i << ' ';
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
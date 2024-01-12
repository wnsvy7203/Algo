#include <iostream>

#define INF 1e9

using namespace std;

int N, d;
int graph[51][51];
string rel;
void input()
{
    cin >> N >> d;
    for (int i = 0; i < N; i++)
    {
        cin >> rel;
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;

            if (rel[j] == 'Y')
                graph[i][j] = d;
            else
                graph[i][j] = INF;
        }
    }
}

void floyd()
{
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

void find_answer()
{
    int ans = 0;
    bool flag = 1;
    for (int i = 0; i < N; i++)
    {
        int tmp = 0;
        for (int j = 0; j < N; j++)
            tmp = max(tmp, graph[i][j]);
        
        if (tmp == INF)
            flag = 0;
        else
            ans = max(ans, tmp);
    }
    
    if (flag)
        cout << ans;
    else
        cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    floyd();
    find_answer();
}
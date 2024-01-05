#include <iostream>

using namespace std;

int N, M;
bool graph[501][501];

void input()
{
    cin >> N >> M;
    while (M--)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }
}

void floyd()
{
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = 1;
}

void find_answer()
{
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        bool flag = 1;
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                continue;

            if (!graph[i][j] && !graph[j][i])
            {
                flag = 0;
                break;
            }
        }
        
        if (flag)
            ans++;
    }

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
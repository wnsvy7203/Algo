#include <iostream>

using namespace std;

int N, M;
bool heavy[100][100];
bool light[100][100];

void input()
{
    cin >> N >> M;
    while (M--)
    {
        int u, v;
        cin >> u >> v;
        heavy[u][v] = 1;
        light[v][u] = 1;
    }
}

void floyd()
{
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                if (heavy[i][k] && heavy[k][j])
                    heavy[i][j] = 1;

                if (light[i][k] && light[k][j])
                    light[i][j] = 1;
            }
}

void find_answer()
{
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int tmp_h = 0;
        int tmp_l = 0;

        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                continue;

            if (heavy[i][j])
                tmp_h++;
            if (light[i][j])
                tmp_l++;
        }

        if (tmp_h >= (N+1)/2 || tmp_l >= (N+1)/2)
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
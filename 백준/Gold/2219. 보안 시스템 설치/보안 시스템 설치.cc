#include <iostream>

#define INF 1e8

using namespace std;

int N, M;
int dp[201][201];

void input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                continue;

            dp[i][j] = INF;
        }

    while (M--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        dp[A][B] = C;
        dp[B][A] = C;
    }
}

void floyd()
{
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
}

void find_answer()
{
    int min_value = INF;
    int ans = 0;

    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
            sum += dp[i][j];
        
        if (min_value > sum)
        {
            min_value = sum;
            ans = i;
        }
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
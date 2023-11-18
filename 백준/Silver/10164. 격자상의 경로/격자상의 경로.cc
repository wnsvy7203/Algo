#include <iostream>

using namespace std;

int N, M, K;
int dp[16][16];

int R, C;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    int num = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            if (num++ == K)
            {
                R = i;
                C = j;
            }
        }
    
    dp[1][1] = 1;
    if (K)
    {
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
                dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i][j-1];
        
        for (int i = R; i <= N; i++)
            for (int j = C; j <= M; j++)
            {
                if (i == R && j == C)
                    continue;
                dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i][j-1];
            }
    }
    else
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i][j-1];
    
    cout << dp[N][M];
}
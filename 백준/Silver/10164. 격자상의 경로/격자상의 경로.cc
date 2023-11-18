#include <iostream>

using namespace std;

int N, M, K;
int board[16][16], dp[16][16];

int R, C;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    int num = 1;    bool flag = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            board[i][j] = num++;
            if (board[i][j] == K)
            {
                flag = 1;
                R = i;
                C = j;
            }
        }
    
    dp[1][1] = 1;
    for (int i = 2; i <= M; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= N; i++)
        dp[i][1] = 1;
    
    if (flag)
    {
        for (int i = 2; i <= R; i++)
            for (int j = 2; j <= C; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        for (int i = C+1; i <= M; i++)
            dp[R][i] = dp[R][C];
        for (int i = R+1; i <= N; i++)
            dp[i][C] = dp[R][C];
        
        for (int i = R+1; i <= N; i++)
            for (int j = C+1; j <= M; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
    else
        for (int i = 2; i <= M; i++)
            for (int j = 2; j <= M; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
    
    cout << dp[N][M];
}
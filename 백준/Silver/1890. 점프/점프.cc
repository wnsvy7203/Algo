//

#include <iostream>

using namespace std;

int N;
int board[101][101];
long long dp[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    
    dp[1][1] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            if (!dp[i][j])
                continue;
            else if (i == N && j == N)
                continue;
            
            if (board[i][j] + i <= N)
                dp[board[i][j] + i][j] += dp[i][j];
            if (board[i][j] + j <= N)
                dp[i][board[i][j] + j] += dp[i][j];
        }
    
    cout << dp[N][N];
}
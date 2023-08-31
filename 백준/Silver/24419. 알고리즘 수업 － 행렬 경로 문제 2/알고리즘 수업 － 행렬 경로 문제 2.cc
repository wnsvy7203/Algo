//

#include <iostream>

#define DIV 1000000007

using namespace std;

int n;
int board[1001][1001];
int dp[1001][1001];

int main()
{
    for (int i = 0; i < 1001; i++)
        dp[0][i] = dp[i][0] = 1;

    for (int i = 1; i < 1001; i++)
        for (int j = 1; j < 1001; j++)
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % DIV;
    
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    cout << dp[n][n] << ' ' << n * n;
}
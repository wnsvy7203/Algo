#include <iostream>

#define MOD 10007

using namespace std;

int N;
int dp[1001][10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 1000; i++)
        dp[i][0] = 1;
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= 1000; i++)
        for (int j = 1; j < 10; j++)
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;

    cin >> N;
    int ans = 0;
    for (int i = 0; i < 10; i++)
        ans += dp[N][i];
    
    cout << ans % MOD;
}
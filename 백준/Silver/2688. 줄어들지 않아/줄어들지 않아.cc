//

#include <iostream>

using namespace std;

int T, n;
long long dp[65][10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    
    for (int i = 2; i < 65; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 9; k >= j; k--)
                dp[i][j] += dp[i-1][k];

    cin >> T;
    while (T--)
    {
        long long ans = 0;

        cin >> n;
        for (int i = 0; i < 10; i++)
            ans += dp[n][i];

        cout << ans << '\n';
    }
}
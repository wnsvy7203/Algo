#include <iostream>

using namespace std;

int N;
int dp[21];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1] = 1;  dp[2] = 2;  dp[3] = 4;  dp[4] = 7;

    for (int i = 5; i <= 20; i++)
    {
        dp[i] = dp[i-1] * 2;

        if (!(i % 2))
            dp[i] -= (dp[i-4] + dp[i-5]);
    }

    cin >> N;
    cout << dp[N];
}
//

#include <iostream>

using namespace std;

int T, N;
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill_n(&dp[0], 1001, 1);

    dp[1] = 1;  dp[3] = 2;
    dp[2] = 2;  dp[4] = 4;

    for (int i = 5; i <= 1000; i++)
    {
        for (int j = 1; j <= i / 2; j++)
            dp[i] += dp[j];
    }

    cin >> T;
    while (T--)
    {
        cin >> N;
        cout << dp[N] <<'\n';
    }
}
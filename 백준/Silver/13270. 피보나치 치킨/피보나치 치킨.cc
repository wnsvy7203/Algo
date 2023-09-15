//

#include <iostream>

using namespace std;

int N;
int dp[10001][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int a = 1, b = 2;

    for (int i = 1; i <= N; i++)
        dp[i][0] = 10000;
    
    while (b <= N)
    {
        for (int i = b; i <= N; i++)
        {
            dp[i][0] = min(dp[i][0], dp[i-b][0]+a);
            dp[i][1] = max(dp[i][1], dp[i-b][1]+a);
        }
        b += a;
        a = b-a;
    }

    cout << dp[N][0] << ' ' << dp[N][1];
}
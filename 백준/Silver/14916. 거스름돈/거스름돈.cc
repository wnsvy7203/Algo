//

#include <iostream>
#include <cstring>

#define MAX 100001

using namespace std;

int n;
int dp[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    dp[2] = 1;  dp[4] = 2;  dp[5] = 1;
    for (int i = 6; i < MAX; i++)
        if (dp[i-2] != -1 && dp[i-5] == -1)
            dp[i] = dp[i-2] + 1;
        else if (dp[i-2] == -1 && dp[i-5] != -1)
            dp[i] = dp[i-5] + 1;
        else if (dp[i-2] != -1 && dp[i-5] != -1)
            dp[i] = min(dp[i-2], dp[i-5]) + 1;

    cin >> n;
    cout << dp[n];
}
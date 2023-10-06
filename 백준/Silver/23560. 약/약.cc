//

#include <iostream>

using namespace std;

int N;
int dp[16], tmp[16];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1] = 2;
    tmp[1] = 1;

    for (int i = 2; i <= 15; i++)
    {
        dp[i] = 2 * dp[i-1] + 2 * tmp[i-1];
        tmp[i] = tmp[i-1] + dp[i-1];
    }

    cin >> N;
    cout << dp[N];
}
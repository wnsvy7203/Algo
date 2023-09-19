//

#include <iostream>

#define MAX 1000001
#define DIV 1000000009

using namespace std;

int T, n;
long long int dp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < MAX; i++)
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % DIV;

    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }
}
//

#include <iostream>

#define MAX 191230
#define DIV 1000000007

using namespace std;

int T, N;
long long int dp[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i < MAX; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % DIV;

    cin >> T;
    while (T--)
    {
        cin >> N;
        cout << dp[N] << '\n';
    }
}
//

#include <iostream>
#include <numeric>

#define DIV 1000000007

using namespace std;

int n;
long long int dp[51];

int main()
{
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i < 51; i++)
        dp[i] = (dp[i-1] + dp[i-2] + 1) % DIV;

    cin >> n;

    cout << dp[n];
}
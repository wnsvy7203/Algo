//

#include <iostream>
#include <algorithm>

#define MAX 100001

using namespace std;

int N;
int dp[MAX];

int main()
{
    dp[1] = dp[2] = dp[5] = dp[7] = 1;
    dp[3] = dp[4] = dp[6] = 2;

    for (int i = 8; i < MAX; i++)
        dp[i] = min({dp[i-1] + 1, dp[i-2] + 1, dp[i-5] + 1, dp[i-7] + 1});
    
    cin >> N;

    cout << dp[N];
}
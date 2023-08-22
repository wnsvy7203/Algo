//

#include <iostream>

using namespace std;

int N;
int dp[11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[2] = 1;
    
    for (int i = 3; i < 11; i++)
        dp[i] = dp[i-1] + i-1;

    cin >> N;

    cout << dp[N];
}
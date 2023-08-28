//

#include <iostream>

#define MAX 10000001

using namespace std;

int n;
int dp[MAX];

int main()
{
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i < MAX; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % 10;
    
    cin >> n;

    cout << dp[n];
}
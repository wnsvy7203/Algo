//

#include <iostream>

#define MAX 1001
#define DIV 1000000007

using namespace std;

int n, m;
long long int dp[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < MAX; i++)
        dp[i][1] = dp[1][i] = 1;
    
    for (int i = 2; i < MAX; i++)
        for (int j = 2; j < MAX; j++)
            dp[i][j] = (dp[i-1][j] + dp[i][j-1] + dp[i-1][j-1]) % DIV;

    cin >> n >> m;

    cout << dp[n][m];
}
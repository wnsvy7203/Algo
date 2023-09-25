//

#include <iostream>

using namespace std;

int N, M;
int dp[11][31];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < 31; i++)
        dp[1][i] = 1;

    for (int i = 1; i < 11; i++)
        dp[i][i] = 1;
    
    for (int i = 2; i < 11; i++)
        for (int j = i; j < 31; j++)
            dp[i][j] = dp[i][j-1] + dp[i-1][j-1];

    cin >> N >> M;
    cout << dp[N][M];
}
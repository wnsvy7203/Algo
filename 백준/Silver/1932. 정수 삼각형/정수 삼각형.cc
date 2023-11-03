//

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int tri[501][501], dp[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> tri[i][j];
    
    dp[1][1] = tri[1][1];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = tri[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
    
    cout << *max_element(dp[n]+1, dp[n]+n+1);
}
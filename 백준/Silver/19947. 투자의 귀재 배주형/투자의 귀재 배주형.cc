//

#include <iostream>

using namespace std;

int H, Y;
int dp[11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> H >> Y;

    for (int i = 0; i < 11; i++)
        dp[i] = H;
    
    for (int i = 1; i < 3; i++)
        dp[i] = int(dp[i-1] * 1.05);

    for (int i = 3; i < 5; i++)
        dp[i] = max(int(dp[i-1] * 1.05), int(dp[i-3] * 1.2));

    for (int i = 5; i < 11; i++)
        dp[i] = max(max(int(dp[i-1] * 1.05), int(dp[i-3] * 1.2)), int(dp[i-5] * 1.35));

    
    cout << dp[Y];
}
//

#include <iostream>

using namespace std;

int D, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> D >> K;
    int dp[D] = {0, };
    for (int i = 1; i <= K/2 ; i++)
    {
        for (int j = i+1; j <= K; j++)
        {
            dp[0] = i;
            dp[1] = j;

            for (int k = 2; k < D; k++)
                dp[k] = dp[k-1] + dp[k-2];
            
            if (dp[D-1] == K)
            {
                cout << dp[0] << '\n' << dp[1];
                return 0;
            }
        }
    }
}
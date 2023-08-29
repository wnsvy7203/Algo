//

#include <iostream>

using namespace std;

int N;
int T[16], P[16];
int dp[16];

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> T[i] >> P[i];
    
    for (int i = N-1; i >= 0; i--)
        if (i + T[i] > N)
            dp[i] = dp[i+1];
        else
            dp[i] = max(dp[i+1], dp[i+T[i]]+P[i]);
    
    cout << dp[0];
}
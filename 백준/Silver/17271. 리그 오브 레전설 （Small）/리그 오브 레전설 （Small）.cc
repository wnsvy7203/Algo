

#include <iostream>

#define DIV 1000000007

using namespace std;

int N, M;
int dp[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    
    dp[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        if (i > M)
            dp[i] = (dp[i-1] + dp[i-M]) % DIV;
        else if (i == M)
            dp[i] = (dp[i-1] + 1) % DIV;
        else
            dp[i] = dp[i-1];
    }

    cout << dp[N];


}
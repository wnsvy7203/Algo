// 같은 수를 2번 이상 연속 사용할 수 없다.
// 원래의 점화식은 dp[n] = dp[n-1] + dp[n-2] + dp[n-3]
// 2번 연속 사용할 수 없으니 2차원 배열로 나눠서
// 마지막 수를 기준으로 더하면서 dp 배열을 구성한다.

#include <iostream>

#define DIV 1000000009

using namespace std;

int T, n;
long long int dp[100001][4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1][1] = 1;  dp[2][2] = 1;
    dp[3][1] = 1;  dp[3][2] = 1;  dp[3][3] = 1;
    for (int i = 4; i < 100001; i++)
    {
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % DIV;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % DIV;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % DIV;
    }
    
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % DIV << '\n';
    }
}
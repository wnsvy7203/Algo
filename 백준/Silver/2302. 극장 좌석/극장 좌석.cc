//

#include <iostream>

using namespace std;

int N, M;
int dp[41];
bool vip[41];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = 1;  dp[1] = 1;  dp[2] = 2;  dp[3] = 3;
    for (int i = 4; i <= 40; i++)
        dp[i] = dp[i-1] + dp[i-2];

    cin >> N >> M;
    int num;
    while (M--)
    {
        cin >> num;
        vip[num] = 1;
    }

    int ans = 1;
    int cnt = 0;
    for (int i = 1; i <= N; i++)
        if (!vip[i])
            cnt++;
        else
        {
            ans *= dp[cnt];
            cnt = 0;
        }
    
    ans *= dp[cnt];
    
    cout << ans;
}
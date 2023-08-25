//

#include <iostream>

using namespace std;

int T, N;
int nums[1001], dp[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        int ans = 0;
        cin >> N;

        for (int i = 0; i < N; i++)
            cin >> nums[i];

        dp[0] = nums[0];
        ans = dp[0];

        for (int i = 1; i < N; i++)
        {
            dp[i] = max(nums[i], nums[i] + dp[i-1]);
            ans = max(ans, dp[i]);
        }

        cout << ans << '\n';
    }
}
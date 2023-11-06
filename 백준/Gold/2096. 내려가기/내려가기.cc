#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int max_dp[3], min_dp[3], nums[3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> max_dp[0] >> max_dp[1] >> max_dp[2];
    for (int i = 0; i < 3; i++)
        min_dp[i] = max_dp[i];

    int n = N-1;
    while (n--)
    {
        cin >> nums[0] >> nums[1] >> nums[2];
        int tmp0 = max_dp[0], tmp1 = max_dp[1];
        max_dp[0] = max(tmp0, tmp1) + nums[0];
        max_dp[1] = max({tmp0, tmp1, max_dp[2]}) + nums[1];
        max_dp[2] = max(tmp1, max_dp[2]) + nums[2];

        tmp0 = min_dp[0], tmp1 = min_dp[1];
        min_dp[0] = min(tmp0, tmp1) + nums[0];
        min_dp[1] = min({tmp0, tmp1, min_dp[2]}) + nums[1];
        min_dp[2] = min(tmp1, min_dp[2]) + nums[2];
    }

    cout << *max_element(max_dp, max_dp+3) << ' ' << *min_element(min_dp, min_dp+3);
    
}
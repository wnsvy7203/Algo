#include <iostream>

#define MAX 10001

using namespace std;

int N;
double nums[MAX];
double dp[MAX];
double ans;

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];

        if (!i)
            dp[i] = nums[i];
        else
            dp[i] = max(nums[i], nums[i] * dp[i-1]);
        
        ans = max(ans, dp[i]);
    }

    cout.precision(3);
    cout << fixed << ans;
}
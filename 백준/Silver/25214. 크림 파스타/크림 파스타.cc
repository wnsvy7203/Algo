//

#include <iostream>

#define MAX 200001

using namespace std;

int N, MIN;
int nums[MAX], dp[MAX];


int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> nums[i];
    
    dp[0] = 0;
    MIN = nums[0];
    for (int i = 1; i < N; i++)
    {
        dp[i] = max(dp[i-1], nums[i] - MIN);
        MIN = min(MIN, nums[i]);
    }

    for (int i = 0; i < N; i++)
        cout << dp[i] << ' ';
}
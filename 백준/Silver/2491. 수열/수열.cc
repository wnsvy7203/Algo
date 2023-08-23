//

#include <iostream>
#include <algorithm>

#define MAX 100001

using namespace std;

int N;
int nums[MAX];
int dp_up[MAX];
int dp_down[MAX];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    dp_up[0] = 1;
    dp_down[0] = 1;
    for (int i = 1; i < N; i++)
    {
        if (nums[i] >= nums[i-1])
            dp_up[i] = dp_up[i-1] + 1;
        else
            dp_up[i] = 1;

        if (nums[i] <= nums[i-1])
            dp_down[i] = dp_down[i-1] + 1;
        else
            dp_down[i] = 1;
    }

    int ma = *max_element(dp_up, dp_up+N);
    int mi = *max_element(dp_down, dp_down+N);

    int ans = ma > mi ? ma : mi;

    cout << ans;
}
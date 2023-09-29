//

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int avg[1001], dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> avg[i];
    
    dp[0] = avg[0];
    int ans = dp[0];
    for (int i = 1; i < N; i++)
    {
        dp[i] = avg[i];
        for (int j = 0; j < i; j++)
            if (avg[i] > avg[j])
                dp[i] = max(dp[i], dp[j] + avg[i]);
    }
    
    cout << *max_element(dp, dp+N);
}
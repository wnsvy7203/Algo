//

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int big[1001];
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> big[i];

    for (int i = 0; i < n; i++)
        dp[i] = 1;
    
    for (int i = 1; i < n; i++)
        for (int j = i-1; j >= 0; j--)
            if (big[i] > big[j])
                dp[i] = max(dp[i], dp[j] + 1);

    cout << *max_element(dp, dp+n);
}
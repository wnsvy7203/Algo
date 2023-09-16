// 28ms

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int A[5001], dp[5001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (A[i] > A[j])
                dp[i] = max(dp[i], dp[j]);
        
        dp[i]++;
    }

    cout << *max_element(dp, dp+n);
}
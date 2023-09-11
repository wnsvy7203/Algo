//

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[1001], dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    for (int i = 0; i < N; i++)
    {
        dp[i] = A[i];
        for (int j = 0; j < i; j++)
            if (A[j] < A[i] && dp[i] < dp[j] + A[i])
                dp[i] = dp[j] + A[i];
    }
    
    cout << *max_element(dp, dp+N);
}
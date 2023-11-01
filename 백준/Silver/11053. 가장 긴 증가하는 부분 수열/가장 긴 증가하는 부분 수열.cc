//

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[1000], dp[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    fill_n(&dp[0], 1000, 1);

    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            if (A[i] > A[j])
                dp[i] = max(dp[i], dp[j] + 1);
    
    cout << *max_element(dp, dp+N);
}
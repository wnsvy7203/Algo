//

#include <iostream>

using namespace std;

int N;
int L[21], J[21];
int dp[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> L[i];
    
    for (int i = 1; i <= N; i++)
        cin >> J[i];
    
    for (int i = 1; i <= N; i++)
        for (int j = 100; j >= L[i]; j--)
            dp[j] = max(dp[j], dp[j-L[i]] + J[i]);
    
    cout << dp[99];
}
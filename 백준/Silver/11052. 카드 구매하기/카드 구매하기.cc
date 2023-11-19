#include <iostream>

using namespace std;

int N;
int cost[1001], dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> cost[i];
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++)
            dp[i] = max(dp[i], dp[i-j] + cost[j]);
    
    cout << dp[N];
}
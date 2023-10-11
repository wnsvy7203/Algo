//

#include <iostream>

#define MAX 300001

using namespace std;

int N;
int tetra[121];
int dp[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 120; i++)
        tetra[i] = i * (i+1) * (i+2) / 6;

    fill_n(&dp[0], MAX, 1000);
    
    cin >> N;
    for (int i = 1; i <= 120; i++)
        dp[tetra[i]] = 1;
    
    for (int i = 1; i <= 120; i++)
        for (int j = tetra[i]; j <= N; j++)
            dp[j] = min(dp[j], dp[j-tetra[i]] + 1);
    
    cout << dp[N];
}
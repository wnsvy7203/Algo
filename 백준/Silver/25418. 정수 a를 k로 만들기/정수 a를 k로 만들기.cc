//

#include <iostream>

#define MAX 1000001

using namespace std;

int A, K;
int dp[MAX];

int main()
{
    cin >> A >> K;

    for (int i = A+1; i <= K; i++)
        if (!(i % 2) && i / 2 >= A)
            dp[i] = min(dp[i-1]+1, dp[i/2]+1);
        else
            dp[i] = dp[i-1]+1;

    cout << dp[K];
}
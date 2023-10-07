//

#include <iostream>

#define MAX 100001
#define DIV 9901

using namespace std;

int N;
int dp[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1] = 3;  dp[2] = 7;

    for (int i = 3; i < MAX; i++)
        dp[i] = (dp[i-1] * 2 + dp[i-2]) % DIV;

    cin >> N;
    cout << dp[N];
}
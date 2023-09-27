#include <iostream>

using namespace std;

int N;
int time[100001][3];
long long int dp[100001][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> time[i][0] >> time[i][1] >> time[i][2];

    dp[0][1] = time[0][2];
    dp[1][1] = time[1][2];
    dp[1][0] = time[0][2];

    for (int i = 2; i < N; i++)
    {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + time[i][2];
    }

    cout << max(dp[N-1][0], dp[N-1][1]);
}
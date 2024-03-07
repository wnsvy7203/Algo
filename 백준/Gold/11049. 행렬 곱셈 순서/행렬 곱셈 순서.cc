#include <iostream>

#define MAX 1e9

using namespace std;

int N;
int arr[501][2], dp[501][501];

void init()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i][0] >> arr[i][1];
}

void dynamic_programming()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= N-i; j++)
        {
            dp[j][i+j] = MAX;
            for (int k = j; k <= i+j; k++)
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + arr[j][0] * arr[k][1] * arr[i+j][1]);
        }
    }

    cout << dp[1][N];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    dynamic_programming();
}
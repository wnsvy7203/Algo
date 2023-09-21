#include <iostream>

using namespace std;

int N, M;
int arr[21][2];
int dp[21][201];

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= M; i++)
        cin >> arr[i][0] >> arr[i][1];
    
    for (int i = 1; i <= M; i++)
        for (int j = 0; j <= N; j++)
        {
            if (j >= arr[i][0])
                dp[i][j] = max(dp[i-1][j-arr[i][0]] + arr[i][1], dp[i-1][j]);

            dp[i][j] = max(dp[i-1][j], dp[i][j]);
        }

    cout << dp[M][N];
}
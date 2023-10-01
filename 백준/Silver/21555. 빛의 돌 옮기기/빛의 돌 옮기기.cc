//

#include <iostream>

#define MAX 200001

using namespace std;

int N, K;
int A[MAX], B[MAX];
long long dp[MAX][2];

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    dp[1][0] = A[1];
    dp[1][1] = B[1];
    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = min(dp[i-1][0], dp[i-1][1] + K) + A[i];
        dp[i][1] = min(dp[i-1][1], dp[i-1][0] + K) + B[i];
    }

    cout << min(dp[N][0], dp[N][1]);
}
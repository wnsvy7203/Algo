#include <iostream>
#include <algorithm>

using namespace std;

int N;
int board[1000][3];
int dp[3][1000][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            cin >> board[i][j];

    int ans = 1e9;

    // 시작점이 0번일 때 다음 차례는 반드시 1번, 2번
    // 시작점이 1번 => 다음은 0번, 2번
    // 시작점이 2번 => 다음은 0번, 1번
    for (int i = 0; i < 3; i++)
        dp[i][0][i] = board[0][i];

    // start => 시작점
    for (int start = 0; start < 3; start++)
    {
        
        for (int i = 0; i < 3; i++)
        {
            if (start == i)
                dp[start][1][i] = 1e9;
            else
                dp[start][1][i] = board[1][i] + dp[start][0][start];
        }

        for (int i = 2; i < N; i++)
        {
            dp[start][i][0] = board[i][0] + min(dp[start][i-1][1], dp[start][i-1][2]);
            dp[start][i][1] = board[i][1] + min(dp[start][i-1][0], dp[start][i-1][2]);
            dp[start][i][2] = board[i][2] + min(dp[start][i-1][0], dp[start][i-1][1]);
        }

        for (int i = 0; i < 3; i++)
        {
            if (start == i)
                continue;

            ans = min(ans, dp[start][N-1][i]);
        }
    }

    cout << ans;
}

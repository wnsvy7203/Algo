#include <iostream>
#include <algorithm>

using namespace std;

int T, N;
int board[100001][3], dp[100001][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1)
    {
        T++;

        cin >> N;
        if (N == 0)
            break;
        
        for (int i = 1; i <= N; i++)
            cin >> board[i][0] >> board[i][1] >> board[i][2];
        
        dp[1][0] = 1000;
        dp[1][1] = board[1][1];
        dp[1][2] = board[1][1] + board[1][2];

        for (int i = 2; i <= N; i++)
        {
            dp[i][0] = board[i][0] + min(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = board[i][1] + min({dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i][0]});
            dp[i][2] = board[i][2] + min({dp[i-1][1], dp[i-1][2], dp[i][1]});
        }

        cout << T << ". " << dp[N][1] << '\n';
    }
}
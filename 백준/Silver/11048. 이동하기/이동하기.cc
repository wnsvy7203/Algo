//

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int board[1001][1001], dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> board[i][j];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            int res = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            dp[i][j] = res + board[i][j];
        }

    cout << dp[N][M];
}
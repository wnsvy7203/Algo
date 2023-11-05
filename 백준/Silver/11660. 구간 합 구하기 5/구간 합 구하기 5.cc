#include <iostream>

using namespace std;

int N, M;
int nums[1025][1025], dp[1025][1025];
int r1, c1, r2, c2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> nums[i][j];
            dp[i][j] = nums[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    
    while (M--)
    {
        cin >> r1 >> c1 >> r2 >> c2;

        cout << dp[r2][c2] - dp[r1-1][c2] - dp[r2][c1-1] + dp[r1-1][c1-1] << '\n';
    }

}
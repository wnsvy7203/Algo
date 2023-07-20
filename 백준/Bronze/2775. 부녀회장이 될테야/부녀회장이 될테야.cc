#include <iostream>
#include <numeric>

using namespace std;

int T;
int k, n;
int dp[15][14];

void apt()
{
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 14; j++)
            if (!i)
                dp[i][j] = j + 1;
            else
                dp[i][j] = accumulate(dp[i-1], dp[i-1]+j+1, 0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

		apt();

    cin >> T;

    while (T--)
    {
        cin >> k >> n;

        cout << dp[k][n-1] << '\n';
    }
}
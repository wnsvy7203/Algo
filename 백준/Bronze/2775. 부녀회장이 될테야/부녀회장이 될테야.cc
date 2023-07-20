#include <iostream>
#include <numeric>

using namespace std;

int T;
int k, n;
int dp[15][15];

int apt(int k, int n)
{
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 14; j++)
            if (!i)
                dp[i][j] = j + 1;
            else
                dp[i][j] = accumulate(dp[i-1], dp[i-1]+j+1, 0);

    return dp[k][n-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> k >> n;

        cout << apt(k, n) << '\n';
    }
}
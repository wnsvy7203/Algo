// 36ms

#include <iostream>

using namespace std;

int a, b, c;
int dp[21][21][21];

void w()
{
    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 21; j++)
        {
            dp[0][i][j] = 1;
            dp[i][0][j] = 1;
            dp[i][j][0] = 1;
        }

    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 21; j++)
            for (int k = 0; k < 21; k++)
                if (dp[i][j][k])
                    continue;
                else if (i < j && j < k)
                    dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
                else
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    w();

    int x, y, z;

    while (1)
    {
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
            return 0;
        else if (a <= 0 || b <= 0 || c <= 0)
            x = y = z = 0;
        else if (a > 20 || b > 20 || c > 20)
            x = y = z = 20;
        else
        {
            x = a;
            y = b;
            z = c;
        }

        cout << "w(" << a << ", " << b << ", " << c << ") = " << dp[x][y][z] << '\n';
    }
}
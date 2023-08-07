// 36ms

#include <iostream>

using namespace std;

int a, b, c;
int dp[21][21][21];

// void w()
// {
//     for (int i = 0; i < 21; i++)
//         for (int j = 0; j < 21; j++)
//         {
//             dp[0][i][j] = 1;
//             dp[i][0][j] = 1;
//             dp[i][j][0] = 1;
//         }

//     for (int i = 0; i < 21; i++)
//         for (int j = 0; j < 21; j++)
//             for (int k = 0; k < 21; k++)
//                 if (dp[i][j][k])
//                     continue;
//                 else if (i < j && j < k)
//                     dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
//                 else
//                     dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
// }

int w(int x, int y, int z)
{
    if (x <= 0 || y <= 0 || z <= 0)
        return 1;
    else if (x > 20 || y > 20 || z > 20)
        return w(20, 20, 20);
    
    if (dp[x][y][z])
        return dp[x][y][z];
    
    if (x < y && y < z)
        dp[x][y][z] = w(x, y, z-1) + w(x, y-1, z-1) - w(x, y-1, z);
    else
        dp[x][y][z] = w(x-1, y, z) + w(x-1, y-1, z) + w(x-1, y, z-1) - w(x-1, y-1, z-1);
    
    return dp[x][y][z];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
            return 0;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
}
// 

#include <iostream>

using namespace std;

int n;
int d[16][16];
int m[16][16];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> m[i][j];
    
    for (int i = 0; i <= n; i++)
        d[i][0] = d[0][i] = 1;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = d[i-1][j] + d[i][j-1];

    cout << d[n][n] << ' ' << n * n;
}
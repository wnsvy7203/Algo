//

#include <iostream>

using namespace std;

int pas[31][31];
int R, C, W;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < 31; i++)
        pas[i][1] = pas[i][i] = 1;

    for (int i = 3; i < 31; i++)
        for (int j = 2; j < i; j++)
            pas[i][j] = pas[i-1][j-1] + pas[i-1][j];

    cin >> R >> C >> W;
    
    int sum = 0;
    for (int i = 0; i < W; i++)
        for (int j = 0; j <= i; j++)
            sum += pas[R+i][C+j];
    
    cout << sum;
}
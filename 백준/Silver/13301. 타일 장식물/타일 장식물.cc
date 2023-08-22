// 

#include <iostream>

using namespace std;

int N;
long long int dp[81];
long long int square[81];

int main()
{
    dp[1] = 1;  square[1] = 4;
    dp[2] = 1;  square[2] = 6;

    for (int i = 3; i < 81; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
        square[i] = square[i-1] + dp[i]*2;
    }

    cin >> N;

    cout << square[N];
}
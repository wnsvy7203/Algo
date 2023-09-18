//

#include <iostream>

using namespace std;

int N;
int dp[10];

int main()
{
    cin >> N;

    dp[1] = 0;
    dp[2] = 2;
    for (int i = 3; i <= 9; i++)
        dp[i] = dp[i-1] * 3;
    
    cout << dp[N];
}
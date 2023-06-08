// Silver 3. 2*n 타일링

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> dp(1001, 0);

void rec()
{
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= 1000; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
}

int main()
{
    cin >> n;

    rec();

    cout << dp[n];
}
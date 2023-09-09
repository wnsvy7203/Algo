//

#include <iostream>

using namespace std;

int N;
int dp[1001];

int main()
{
    cin >> N;
    
    dp[1] = 1;
    dp[3] = 1;

    for (int i = 5; i <= 1000; i++)
        if (!dp[i-1] && !dp[i-3] && !dp[i-4])
            dp[i] = 1;
    
    if (dp[N])
        cout << "CY";
    else
        cout << "SK";
}
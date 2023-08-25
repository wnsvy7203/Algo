//

#include <iostream>

#define MAX 200001

using namespace std;

int N;
int road[MAX];
int dp[MAX];

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> road[i];

    for (int i = N-1; i >= 0; i--)
    {
        if (i + road[i] >= N-1)
            dp[i] = 1;
        else
            dp[i] = dp[i+road[i]+1] + 1;
    }
    
    for (int i = 0; i < N; i++)
        cout << dp[i] << ' ';
}
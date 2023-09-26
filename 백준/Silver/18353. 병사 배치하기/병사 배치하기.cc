//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int sol[2001], dp[2001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> sol[i];
        dp[i] = 1;
    }


    for (int i = 2; i <= N; i++)
        for (int j = 1; j < i; j++)
            if (sol[j] > sol[i])
                dp[i] = max(dp[i], dp[j] + 1);

    cout << N - *max_element(dp+1, dp+N+1);
}
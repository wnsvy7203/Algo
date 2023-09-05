//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int table[100001][6];
int dp[100001][6];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int A, B;
    for (int i = 0; i < N; i++)
    {
        cin >> A >> B;
        table[i][A] = 1;  dp[i][A] = 1;
        table[i][B] = 1;  dp[i][B] = 1;
    }

    int ans1 = 1;
    int ans2 = 1;

    for (int i = 1; i <= 5; i++)
        for (int j = 1; j < N; j++)
            if (dp[j-1][i] && dp[j][i])
            {
                dp[j][i] = dp[j-1][i] + 1;
                if (ans1 < dp[j][i])
                {
                    ans1 = dp[j][i];
                    ans2 = i;
                }
            }

    cout << ans1 << ' ' << ans2;
}
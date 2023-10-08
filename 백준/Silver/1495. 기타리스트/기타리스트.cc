//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S, M;
int V[51];
bool dp[51][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S >> M;
    for (int i = 1; i <= N; i++)
        cin >> V[i];
    
    if (S + V[1] <= M)
        dp[1][S + V[1]] = 1;
    if (S - V[1] >= 0)
        dp[1][S - V[1]] = 1;

    for (int i = 2; i <= N; i++)
        for (int j = 0; j <= M; j++)
            if (dp[i-1][j])
            {
                if (j + V[i] <= M)
                    dp[i][j + V[i]] = 1;
                if (j - V[i] >= 0)
                    dp[i][j - V[i]] = 1;
            }

    for (int i = M; i >= 0; i--)
        if (dp[N][i])
        {
            cout << i;
            return 0;
        }

    cout << -1;
}
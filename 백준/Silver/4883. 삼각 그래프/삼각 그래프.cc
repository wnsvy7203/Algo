#include <iostream>
#include <algorithm>

#define MAX 100001

using namespace std;

int graph[MAX][3], dp[MAX][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    while (1)
    {
        ans++;
        int N;
        cin >> N;

        if (!N)
            break;
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < 3; j++)
                cin >> graph[i][j];
        
        dp[0][0] = 987654321;
        dp[0][1] = graph[0][1];
        dp[0][2] = graph[0][1] + graph[0][2];

        for (int i = 1; i < N; i++)
        {
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + graph[i][0];
            dp[i][1] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i][0]}) + graph[i][1];
            dp[i][2] = min({dp[i-1][1], dp[i-1][2], dp[i][1]}) + graph[i][2];
        }

        cout << ans << ". " << dp[N-1][1] << '\n';
    }
}
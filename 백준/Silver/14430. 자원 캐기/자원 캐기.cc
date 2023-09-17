//

#include <iostream>

using namespace std;

int N, M;
int WOOK[301][301], dp[301][301];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> WOOK[i][j];
        
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + WOOK[i][j];
    
    cout << dp[N][M];
}
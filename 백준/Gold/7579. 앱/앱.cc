#include <iostream>

using namespace std;

int N, M, memory[100], cost[100];
void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> memory[i];
    for (int i = 0; i < N; i++)
        cin >> cost[i];
}

int dp[101][10001];
void dynamic()
{
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < 10001; j++)
        {
            dp[i][j] = dp[i-1][j];
            
            // 현재 앱을 선택하는 경우
            if (j >= cost[i-1])
                dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i-1]] + memory[i-1]);
        }
}

int ans = 0;
void find_answer()
{
    for (int i = 0; i < 10001; i++)
        if (dp[N][i] >= M)
        {
            ans = i;
            break;
        }
    
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    dynamic();
    find_answer();
}
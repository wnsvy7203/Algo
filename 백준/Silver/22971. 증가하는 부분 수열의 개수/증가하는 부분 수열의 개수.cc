//

#include <iostream>

#define DIV 998244353

using namespace std;

int N;
int A[5001];
long long dp[5001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    
    fill_n(&dp[1], 5000, 1);
    for (int i = 2; i <= N; i++)
        for (int j = 1; j < i; j++)
            if (A[i] > A[j])
                dp[i] = (dp[i] + dp[j]) % DIV;
    
    for (int i = 1; i <= N; i++)
        cout << dp[i] << ' ';
}
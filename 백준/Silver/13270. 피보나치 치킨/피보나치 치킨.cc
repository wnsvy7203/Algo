//

#include <iostream>

using namespace std;

int N;
int dp1[10001];     // 최솟값 담는 배열
int dp2[10001];     // 최댓값 담는 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int a = 1, b = 2;

    for (int i = 1; i <= N; i++)
        dp1[i] = 10000;
    
    while (b <= N)
    {
        for (int i = b; i <= N; i++)
        {
            dp1[i] = min(dp1[i], dp1[i-b]+a);
            dp2[i] = max(dp2[i], dp2[i-b]+a);
        }
        b += a;
        a = b-a;
    }

    cout << dp1[N] << ' ' << dp2[N];
}
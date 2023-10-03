//

#include <iostream>
#include <algorithm>

#define MAX 100001

using namespace std;

int N, K;
int L[MAX], dp[MAX];

int cal(bool flag, int idx)
{
    int res = 1;

    for (int i = idx; i < N; i++)
        if (L[i] <= K)
            res++;
        else if (flag)
        {
            res++;
            flag = 0;
        }
        else
            break;

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i < N; i++)
        cin >> L[i];
    
    for (int i = 0; i < N; i++)
        if (L[i] > K || !L[i])
            dp[i+1] = cal(1, i+1);

    cout << *max_element(dp+1, dp+N+1);
}
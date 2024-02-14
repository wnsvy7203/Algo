#include <iostream>
#include <algorithm>

using namespace std;

int N, A[1000];
int incre[1000], decre[1000], dp[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    fill_n(&incre[0], 1000, 1);
    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            if (A[i] > A[j])
                incre[i] = max(incre[i], incre[j]+1);

    fill_n(&decre[0], 1000, 1);
    for (int i = N-2; i >= 0; i--)
        for (int j = i+1; j < N; j++)
            if (A[i] > A[j])
                decre[i] = max(decre[i], decre[j]+1);
    
    for (int i = 0; i < N; i++)
        dp[i] = incre[i] + decre[i] - 1;
    
    cout << *max_element(dp, dp+N);
}
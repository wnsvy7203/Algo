//

#include <iostream>
#include <string>

using namespace std;

string A, B;

int cnt[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int dp[4000];

void make_dp()
{
    cin.tie(NULL);
    cin >> A >> B;

    for (int i = 0; i < A.size(); i++)
    {
        dp[i*2] = cnt[A[i]-65];
        dp[i*2+1] = cnt[B[i]-65];
    }
    
    int len = A.size()*2;
    while (len > 2)
    {
        for (int i = 0; i < len-1; i++)
            dp[i] = (dp[i] + dp[i+1]) % 10;
        len--;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);

    make_dp();
    cout << dp[0] << dp[1];
}
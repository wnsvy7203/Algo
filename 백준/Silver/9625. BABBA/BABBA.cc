//

#include <iostream>

using namespace std;

int dp_A[46];
int dp_B[46];

int K;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp_A[0] = 1; dp_A[1] = 0;
    dp_B[0] = 0; dp_B[1] = 1;

    for (int i = 2; i <= 45; i++)
    {
        dp_A[i] = dp_B[i-1];
        dp_B[i] = dp_A[i-1] + dp_B[i-1];
    }

    cin >> K;

    cout << dp_A[K] << ' ' << dp_B[K];
}
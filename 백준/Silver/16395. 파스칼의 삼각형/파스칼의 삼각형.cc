//

#include <iostream>

using namespace std;

int n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    n--;    k--;
    if (k > n/2)
        k = n-k;

    long long int ans = 1;
    for (int i = n; i > n-k; i--)
        ans *= i;

    for (int i = k; i > 1; i--)
        ans /= i;

    cout << ans;
}
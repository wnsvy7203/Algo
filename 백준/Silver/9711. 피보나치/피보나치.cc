//

#include <iostream>

using namespace std;

int T, P, Q;
int dp[10001] = {1, 1, 2};

int fibo(int p, int q)
{
    unsigned int one = 1;
    unsigned int two = 1;

    if (p == 1 || p == 2)
        if (q == 1)
            return 0;
        else
            return 1;

    for (int i = 3; i <= p; i++)
    {
        unsigned int tmp = (one + two) % q;
        one = two;
        two = tmp;
    }

    return two;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int x = 1; x <= T; x++)
    {
        cin >> P >> Q;

        cout << "Case #" << x << ": " << fibo(P, Q) << '\n';
    }
}
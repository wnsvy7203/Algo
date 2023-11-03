#include <iostream>

using namespace std;

long long A, B, C;

long long power(long long b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return A % C;
    
    long long mod = power(b/2) % C;

    if (!(b % 2))
        return mod * mod % C;
    return mod * mod % C * A % C;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B >> C;

    cout << power(B);
}
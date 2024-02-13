// 8ms

#include <iostream>

#define MOD 1'000'000'007

using namespace std;

long long M, N, S, g, ans;

long long Fermat(long long a, long long b)
{
    if (b == 1)
        return a;
    else if (b % 2)
        return a * Fermat(a, b-1) % MOD;
    
    return Fermat(a, b/2) * Fermat(a, b/2) % MOD;
}

long long gcd(long long a, long long b)
{
    if (a < b)
        swap(a, b);
    
    while (b)
    {
        long long tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> M;
    while (M--)
    {
        cin >> N >> S;
        g = gcd(N, S);
        
        N /= g;
        S /= g;

        ans += (S * Fermat(N, MOD-2)) % MOD;
        ans %= MOD;
    }

    cout << ans;
}
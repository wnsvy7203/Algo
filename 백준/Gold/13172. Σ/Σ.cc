#include <iostream>

#define MOD 1'000'000'007

using namespace std;

long long M, N, S, g, ans;

long long sigma(long long a, long long b)
{
    if (b == 1)
        return a;
    else if (b%2)
        return a * sigma(a, b-1) % MOD;
    
    long long x = sigma(a, b/2);
    return x * x % MOD;
}

long long gcd(long long a, long long b)
{
    if (a < b)
    {
        long long tmp = a;
        a = b;
        b = tmp;
    }
    
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

        ans += (S * sigma(N, MOD-2)) % MOD;
        ans %= MOD;
    }

    cout << ans;
}
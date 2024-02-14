#include <iostream>
#include <map>

#define DIV 1'000'000'007

using namespace std;

long long n;
map<long long, long long> m;

long long fibo(long long x)
{
    if (x == 0 || x == 1)
        return x;
    else if (x == 2)
        return 1;

    if (m[x])
        return m[x];

    if (!(x % 2))
        m[x] = fibo(x/2) * ((fibo(x/2+1) + fibo(x/2-1)) % DIV) % DIV;
    else
        m[x] = ((fibo((x+1)/2) * fibo((x+1)/2) % DIV) + (fibo((x-1)/2) * fibo((x-1)/2) % DIV)) % DIV;
    
    return m[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cout << fibo(n);
}
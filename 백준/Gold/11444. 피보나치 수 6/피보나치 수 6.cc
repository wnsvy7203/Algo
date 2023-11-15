#include <iostream>
#include <map>

#define DIV 1000000007

using namespace std;

unsigned long long n;
map<unsigned long long, unsigned long long> m;

unsigned long long fibo(unsigned long long x)
{
    if (m[x])
        return m[x];

    if (!(x % 2))
        m[x] = ((fibo(x/2) % DIV) * ((fibo(x/2+1) % DIV + fibo(x/2-1) % DIV) % DIV)) % DIV;
    else
        m[x] = ((((fibo((x+1)/2) % DIV) * (fibo((x+1)/2) % DIV)) % DIV) + (((fibo((x-1)/2) % DIV) * (fibo((x-1)/2) % DIV)) % DIV)) % DIV;
    
    return m[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    m[0] = 0;
    m[1] = m[2] = 1;

    cin >> n;
    cout << fibo(n);
}
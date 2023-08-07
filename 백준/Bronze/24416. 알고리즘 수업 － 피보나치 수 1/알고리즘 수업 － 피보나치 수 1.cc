// 36ms

#include <iostream>

using namespace std;

int n;
int cnt = 0;

int fib(int x)
{
    if (x == 1 || x == 2)
        cnt++;
    else
        fib(x-1) + fib(x-2);
    
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cout << fib(n) << ' ' << n-2;
}
// Bronze 1. Lowest Common Multiple, Greatest Common Divisor

#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;

    cout << gcd(a, b) << '\n' << lcm(a, b);
}

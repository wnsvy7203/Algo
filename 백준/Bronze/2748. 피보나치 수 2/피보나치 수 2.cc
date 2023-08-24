//

#include <iostream>

using namespace std;

int n;
long long int fibo[91];

int main()
{
    fibo[1] = 1;

    for (int i = 2; i < 91; i++)
        fibo[i] = fibo[i-1] + fibo[i-2];

    cin >> n;

    cout << fibo[n];
}
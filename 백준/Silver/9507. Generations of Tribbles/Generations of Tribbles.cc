//

#include <iostream>
#include <cmath>

using namespace std;

int t, n;
long long int fibo[68];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fibo[0] = 1;
    fibo[1] = 1;
    fibo[2] = 2;
    fibo[3] = 4;
    for (int i = 4; i < 68; i++)
        fibo[i] = fibo[i-1] + fibo[i-2] + fibo[i-3] + fibo[i-4];

    cin >> t;

    while (t--)
    {
        cin >> n;

        cout << fibo[n] << '\n';
    }
}
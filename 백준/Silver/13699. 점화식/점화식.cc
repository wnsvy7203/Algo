//

#include <iostream>

using namespace std;

int n;
long long int t[36];

int main()
{
    t[0] = 1;

    for (int i = 1; i < 36; i++)
        for (int j = 0; j < i; j++)
            t[i] += t[j] * t[i-1-j];
    
    cin >> n;

    cout << t[n];
}
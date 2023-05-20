// Bronze 2. Hashing

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int r = 31, M = 1234567891;

    long long int sum = 0;

    int L;
    
    string str;

    cin >> L >> str;

    for (int i = 0; i < L; i++)
    {
        sum += (str[i] - 96) * pow(r, i);
    }

    cout << sum % M;
}

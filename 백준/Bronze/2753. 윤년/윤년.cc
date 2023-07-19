// Bronze 5
// ����

#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    if (!(n % 4))
        if (!(n % 400))
            cout << 1;
        else if (n % 100)
            cout << 1;
        else
            cout << 0;
    else
        cout << 0;
}
#include <iostream>

using namespace std;

int X;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> X;
    int cnt = 0;
    for (int i = 0; i <= 6; i++)
        if (X & (1 << i))
            cnt++;

    cout << cnt;
}
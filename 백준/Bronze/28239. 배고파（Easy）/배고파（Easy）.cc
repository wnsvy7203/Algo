#include <iostream>

using namespace std;

int n;
long long m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n--)
    {
        cin >> m;
        for (int x = 0; x < 64; x++)
            for (int y = x; y < 64; y++)
                if ((1LL << x) + (1LL << y) == m)
                {
                    cout << x << ' ' << y << '\n';
                    break;
                }
    }
}
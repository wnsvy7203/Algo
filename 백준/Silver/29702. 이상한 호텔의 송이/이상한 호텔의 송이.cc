#include <iostream>
#include <string>

using namespace std;

int T;
long long N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
    {
        cin >> N;
        int floor = 0;
        for (int i = 59; i >= 0; i--)
        {
            if ((N >> i) & 1)
            {
                floor = i+1;
                break;
            }
        }

        while (N)
        {
            cout << floor;
            floor--;
            long long room = N - (1LL << floor) + 1;
            int len = to_string(room).length();

            for (int i = 1; i <= 18-len; i++)
                cout << '0';

            cout << room << '\n';
            N >>= 1;
        }
    }
}
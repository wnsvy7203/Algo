#include <iostream>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp = 0;
        for (int j = 0; j <N; j++)
        {
            int m;
            cin >> m;
            tmp |= m;
        }

        cout << tmp << ' ';
    }
}
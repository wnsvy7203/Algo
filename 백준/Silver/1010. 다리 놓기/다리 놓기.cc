// Silver 5. Building Bridge

#include <iostream>

using namespace std;

int main()
{
    int T;

    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int N, M;

        cin >> N >> M;

        long long int cnt = 1;

        for (int i = M; i > M-N; i--)
        {
            cnt *= i;
            cnt /= M-i+1;
        }

        cout << cnt << '\n';
    }
}
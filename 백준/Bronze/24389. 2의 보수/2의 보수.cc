// 어떤 수의 2의 보수는, 해당하는 숫자의 모든 비트를 반전시킨 뒤, 1을 더해 만들 수 있다.
// C의 정수자료형에서 1 이상의 자연수 N의 2의 보수는 -N과 같다.

#include <iostream>

using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    M = (~N + 1);
    int cnt = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((M & 1) != (N & 1))
            cnt++;
        N >>= 1;
        M >>= 1;
    }

    cout << cnt;
}
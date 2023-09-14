//

#include <iostream>

using namespace std;

int N, M;
bool dp[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    if ((N % 2) && (M % 2))
        cout << 'B';
    else
        cout << 'A';
}
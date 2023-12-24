#include <iostream>
#include <algorithm>

using namespace std;

int N;
string K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    int ans = 0;
    for (int i = 0; i < N; i++)
        if (K[i] == '1')
            ans++;
    
    cout << ans;
}
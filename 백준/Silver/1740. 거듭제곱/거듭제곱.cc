#include <iostream>

using namespace std;

long long N, ans, s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    s = 1;
    while (N)
    {
        if (N & 1)
            ans += s;
        
        s *= 3;
        N >>= 1;
    }
    
    cout << ans;
}
//

#include <iostream>

#define DIV 1000000007

using namespace std;

int n, ans;

int main()
{
    cin >> n;

    int tmp1 = 0;
    int tmp2 = 1;
    int tmp3 = 1;

    for (int i = 1; i <= n-2; i++)
    {
        ans = (tmp2 + tmp3) % DIV;
        tmp1 = tmp2;
        tmp2 = tmp3;
        tmp3 = ans;
    }
        

    cout << ans << ' ' << n-2;
}
// 496ms

#include <iostream>
#include <cmath>

#define MAX 1000001
#define DIV 1000000

using namespace std;

int i;
int ans[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ans[0] = 1;
    for (int x = 1; x < MAX; x++)
    {
        int a = (int)(x-sqrt(x));
        int b = (int)log(x);
        int c = (int)(x*sin(x)*sin(x));

        ans[x] = (ans[a] + ans[b] + ans[c]) % DIV;
    }

    while (cin >> i)
    {
        if (i == -1)
            return 0;
        
        cout << ans[i] << '\n';
    }
}
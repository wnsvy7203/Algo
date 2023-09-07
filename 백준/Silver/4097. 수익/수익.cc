//

#include <iostream>
#include <cstring>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> N)
    {
        if (!N)
            return 0;
        
        int ans = -10000;
        int sum = 0;
        int input;
        for (int i = 0; i < N; i++)
        {
            cin >> input;
            sum = sum + input > input ? sum + input : input;            
            ans = max(ans, sum);
        }
        cout << ans << '\n';
    }
}
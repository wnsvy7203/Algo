//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string dp[251];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = "1";
    dp[1] = "1";

    for (int i = 2; i <= 250; i++)
    {
        string x = dp[i-2];

        reverse(x.begin(), x.end());

        int plus = 0;
        string res = "";

        for (int j = 0; j < x.size(); j++)
        {
            int tmp = (x[j] - 48) * 4 + plus;

            if (!j)
                if (!(i % 2))
                    tmp -= 1;
                else
                    tmp += 1;

            if (tmp > 9)
            {
                plus = tmp / 10;
                tmp %= 10;
            }
            else
                plus = 0;
            
            res += char(tmp + 48);
        }

        if (plus)
            res += char(plus + 48);
        
        reverse(res.begin(), res.end());
        dp[i] = res;
    }

    while (cin >> n)
        cout << dp[n] << '\n';
}
#include <iostream>
#include <algorithm>

using namespace std;

int N;
string K;

string cal(string a)
{
    reverse(a.begin(), a.end());
    int cnt = 0;
    for (char c : a)
    {
        if (c == '0')
            cnt++;
        else
        {
            cnt++;
            break;
        }
    }

    string b = "";
    for (int i = 0; i < cnt; i++)
        b += '1';
    
    int len = a.length();
    string c = "";
    for (int i = 0; i < cnt; i++)
        c += '0';
    for (int i = cnt; i < len; i++)
        c += a[i];
    
    reverse(c.begin(), c.end());
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    int ans = 1;
    while (1)
    {
        K = cal(K);

        int len = K.length();
        bool flag = 1;
        for (int i = 0; i < len; i++)
            if (K[i] == '1')
            {
                flag = 0;
                break;
            }
        
        if (flag)
        {
            cout << ans;
            break;
        }
        else
            ans++;
    }
}
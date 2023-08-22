//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string fibo[10001];

string dp(string a, string b)
{
    // b가 반드시 작다.
    string res = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int len_A = a.size();
    int len_B = b.size();

    int ten = 0;
    for (int i = 0; i < len_B; i++)
    {
        int tmp = (a[i]-48) + (b[i]-48) + ten;
        if (tmp > 9)
            ten = 1;
        else
            ten = 0;

        tmp %= 10;

        res += char(tmp+48);
    }

    for (int i = len_B; i < len_A; i++)
    {
        int tmp = (a[i]-48) + ten;
        if (tmp > 9)
            ten = 1;
        else
            ten = 0;
        
        tmp %= 10;
        res += char(tmp+48);
    }

    if (ten)
        res += '1';

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fibo[0] = "0";
    fibo[1] = "1";

    for (int i = 2; i < 10001; i++)
        fibo[i] = dp(fibo[i-1], fibo[i-2]);
    
    cin >> n;

    cout << fibo[n];
}
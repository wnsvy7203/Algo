//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAX 1001

using namespace std;

string a, b;
vector<string> fibo;

void dp()
{
    fibo.push_back("1");
    fibo.push_back("2");

    while (fibo[fibo.size()-1].size() <= 100)
    {
        string x = fibo[fibo.size()-1]; // 큰 수
        string y = fibo[fibo.size()-2]; // 작은 수

        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());

        int one = 0;

        string res = "";

        for (int i = 0; i < y.size(); i++)
        {
            int tmp = (x[i]-48) + (y[i]-48) + one;

            if (tmp > 9)
            {
                one = 1;
                tmp -= 10;
            }
            else
                one = 0;
            
            res += char(tmp+48);
        }

        for (int i = y.size(); i < x.size(); i++)
        {
            int tmp = (x[i]-48) + one;

            if (tmp > 9)
            {
                one = 1;
                tmp -= 10;
            }
            else
                one = 0;
            
            res += char(tmp+48);
        }

        if (one)
            res += '1';

        reverse(res.begin(), res.end());
        fibo.push_back(res);
    }
}

bool operator<=(const string &a, const string &b)
{
    if (a.size() == b.size())
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] > b[i])
                return 0;
            else if (a[i] < b[i])
                return 1;
        }
        return 1;
    }
    else if (a.size() < b.size())
        return 1;
    else
        return 0;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp();

    while (1)
    {
        cin >> a >> b;

        if (a == "0" && b == "0")
            return 0;
        
        int cnt = 0;
        for (int i = 0; i < fibo.size(); i++)
            if (a <= fibo[i] && fibo[i] <= b)
                cnt++;
            
        cout << cnt << '\n';
    }
}
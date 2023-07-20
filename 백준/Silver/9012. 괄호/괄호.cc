#include <iostream>
#include <stack>
#include <string>

using namespace std;

int T;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;

    while (T--)
    {
        stack<char> stk;

        bool check = 1;

        string p;

        cin >> p;

        for (int i = 0; i < p.length(); i++)
            if (p[i] == '(')
                stk.push(1);
            else if (p[i] == ')')
                if (stk.empty())
                {
                    check = 0;
                    break;
                }
                else
                    stk.pop();

        if (check)
            if (stk.empty())
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        else
            cout << "NO" << '\n';
    }
}
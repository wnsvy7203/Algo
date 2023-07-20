// Silver 4. Stack
// 336ms

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N;
stack<int> stk;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i <= N; i++)
    {
        string str;

        cin >> str;

        if (str == "push")
        {
            int num;

            cin >> num;

            stk.push(num);
        }
        else if (str == "pop")
        {
            if (!stk.size())
                cout << -1 << '\n';
            else
            {
                cout << stk.top() << '\n';
                stk.pop();
            }
        }
        else if (str == "size")
            cout << stk.size() << '\n';
        else if (str == "empty")
            cout << stk.empty() << '\n';
        else if (str == "top")
            if (!stk.size())
                cout << -1 << '\n';
            else
                cout << stk.top() << '\n';
    }
}
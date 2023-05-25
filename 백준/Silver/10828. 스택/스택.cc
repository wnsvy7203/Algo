// Silver 4. Stack

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int N;

    cin >> N;

    stack<int> stk;

    for (int i = 0; i <= N; i++)
    {
        string str;

        getline(cin, str);

        if (str == "")
            continue;

        if (str == "pop")
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
        {
            cout << stk.size() << '\n';
        }
        else if (str == "empty")
        {
            cout << stk.empty() << '\n';
        }
        else if (str == "top")
        {
            if (!stk.size())
                cout << -1 << '\n';
            else
                cout << stk.top() << '\n';
        }
        else
        {
            string integer;

            int idx = 0;

            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == ' ')
                {
                    idx = i + 1;
                    break;
                }

            }

            stk.push(stoi(str.substr(idx, 7)));
        }
    }
}
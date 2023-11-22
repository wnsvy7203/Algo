#include <iostream>
#include <stack>

using namespace std;

string str, ans;

stack<char> cal;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;

    // 사칙연산, 괄호로만 이루어진 연산
    for (int i = 0; i < str.size(); i++)
        if (str[i] >= 65 && str[i] <= 90)
            cout << str[i];
        else if (str[i] == ')')
        {
            while (cal.top() != '(')
            {
                cout << cal.top();
                cal.pop();
            }

            cal.pop();
        }
        else if (str[i] == '*' || str[i] == '/')
        {
            while (!cal.empty() && (cal.top() == '*' || cal.top() == '/'))
            {
                cout << cal.top();
                cal.pop();
            }
            cal.push(str[i]);
        }
        else if (str[i] == '+' || str[i] == '-')
        {
            while (!cal.empty() && cal.top() != '(')
            {
                cout << cal.top();
                cal.pop();
            }
            cal.push(str[i]);
        }
        else
            cal.push(str[i]);
    
    while (!cal.empty())
    {
        cout << cal.top();
        cal.pop();
    }
}
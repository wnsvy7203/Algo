//

#include <iostream>
#include <stack>

using namespace std;

int N;
stack<int> stk;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    int o;

    while (N--)
    {
        cin >> o;

        switch (o)
        {
            case 1:
            {
                int num;
                cin >> num;

                stk.push(num);
                break;
            }
            case 2:
            {
                if (!stk.empty())
                {
                    cout << stk.top();
                    stk.pop();
                    break;
                }
                else
                    cout << -1;
                break;
            }
            case 3:
            {
                cout << stk.size();
                break;
            }
            case 4:
            {
                if (stk.empty())
                    cout << 1;
                else
                    cout << 0;
                break;
            }
            case 5:
            {
                if (!stk.empty())
                    cout << stk.top();
                else
                    cout << -1;
                break;
            }
        }

        if (o != 1)
            cout << '\n';
    }
}
//

#include <iostream>
#include <deque>

using namespace std;

int N, X;
deque<int> deq;

int arr[1001];

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
                cin >> X;
                deq.push_front(X);
                break;
            }
            case 2:
            {
                cin >> X;
                deq.push_back(X);
                break;
            }
            case 3:
                if (!deq.empty())
                {
                    int f = deq.front();
                    cout << f;
                    deq.pop_front();
                }
                else
                    cout << -1;
                break;
            case 4:
                if (!deq.empty())
                {
                    int b = deq.back();
                    cout << b;
                    deq.pop_back();
                }
                else
                    cout << -1;
                break;
            case 5:
                cout << deq.size();
                break;
            case 6:
                cout << deq.empty();
                break;
            case 7:
                if (!deq.empty())
                    cout << deq.front();
                else
                    cout << -1;
                break;
            case 8:
                if (!deq.empty())
                    cout << deq.back();
                else
                    cout << -1;
                break;
        }       

        if (o != 1 && o != 2)
            cout << '\n';
    }
}
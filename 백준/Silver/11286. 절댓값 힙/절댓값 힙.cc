// Silver 1. ABS Heap

#include <iostream>
#include <queue>

using namespace std;

int N;

int main()
{
    priority_queue<pair<int, int>> pque;
    
    cin >> N;

    while (N--)
    {
        int x;

        cin >> x;

        if (x)
            pque.push(make_pair(-abs(x), -x));
        else
        {
            if (pque.empty())
                cout << 0 << '\n';
            else
            {
                cout << -pque.top().second << '\n';
                pque.pop();
            }
        }
    }
}
// Silver 5. Josephus Problem 0

#include <iostream>
#include <queue>

using namespace std;

int N, K;
queue<int> que;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        que.push(i);

    cout << '<';

    while (!que.empty())
    {
        for (int i = 1; i < K; i++)
        {
            int f = que.front();
            que.pop();
            que.push(f);
        }

        int front = que.front();

        if (que.size() == 1)
        {
            cout << front << '>';
            return 0;
        }
        else
        {
            cout << front << ", ";
            que.pop();
        }
    }
}
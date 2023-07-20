// 

#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> que;

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
        que.push(i);

    while (que.size() != 1)
    {
        que.pop();

        int front = que.front();

        que.pop();
        que.push(front);
    }

    cout << que.front();
}
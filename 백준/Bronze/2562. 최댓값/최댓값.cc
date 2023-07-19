#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>> que;

int main()
{
    cin.tie(0);

    int num = 0;

    for (int i = 1; i <= 9; i++)
    {
        cin >> num;
        que.push({num, i});
    }

    cout << que.top().first << '\n' << que.top().second;
}
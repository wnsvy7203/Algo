// 4ms

#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int C, S, T;

int bfs(int x, int y)
{
    queue<tuple<int, int, int>> que;

    que.push({x, y, 0});

    while (!que.empty())
    {
        int front = get<0>(que.front());
        int end = get<1>(que.front());
        int cnt = get<2>(que.front());
        que.pop();

        if (front == end)
            return cnt;

        if (front*2 <= end+3)
            que.push({front*2, end+3, cnt+1});

        if (front+1 <= end)
            que.push({front+1, end, cnt+1});
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> C;
    
    while (C--)
    {
        cin >> S >> T;
    
        cout << bfs(S, T) << '\n';
    }
}
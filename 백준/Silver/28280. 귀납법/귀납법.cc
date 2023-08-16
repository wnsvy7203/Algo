// 

#include <iostream>
#include <queue>

#define MAX 4000001

using namespace std;

int T, k;
int visited[MAX];

queue<int> que;

void bfs()
{
    que.push(1);
    visited[1] = 1;

    while (!que.empty())
    {
        int f = que.front();
        que.pop();

        if (f-1 > 0 && !visited[f-1])
        {
            que.push(f-1);
            visited[f-1] = visited[f] + 1;
        }

        if (f*2 < MAX && !visited[f*2])
        {
            que.push(f*2);
            visited[f*2] = visited[f] + 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    bfs();

    while (T--)
    {
        cin >> k;
        
        if (visited[k])
            cout << visited[k] - 1 << '\n';
        else
            cout << "Wrong proof!\n";
    }
}
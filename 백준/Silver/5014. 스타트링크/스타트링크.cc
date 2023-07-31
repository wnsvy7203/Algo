// 40ms

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int F, S, G, U, D;
int visited[1000001];

queue<int> que;

void bfs(int s, int g)
{
    que.push(s);
    visited[s] = 1;

    while (!que.empty())
    {
        int q = que.front();
        que.pop();

        if (q == g)
        {
            cout << visited[g] - 1;
            break;
        }
        
        if (q+U <= F && !visited[q+U])
        {
            que.push(q+U);
            visited[q+U] = visited[q] + 1;
        }

        if (q-D > 0 && !visited[q-D])
        {
            que.push(q-D);
            visited[q-D] = visited[q] + 1;
        }
    }

    if (!visited[g])
        cout << "use the stairs";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> F >> S >> G >> U >> D;

    bfs(S, G);
}
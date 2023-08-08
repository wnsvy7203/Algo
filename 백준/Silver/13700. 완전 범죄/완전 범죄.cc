// 8ms

#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;

int N, S, D, F, B, K;

queue<int> que;
int visited[MAX];

void bfs(int s)
{
    que.push(s);
    visited[s] = 1;

    while (!que.empty())
    {
        int f = que.front();
        que.pop();

        if (f == D)
            break;

        if (f+F < MAX && !visited[f+F])
        {
            que.push(f+F);
            visited[f+F] = visited[f] + 1;
        }

        if (f-B > 0 && !visited[f-B])
        {
            que.push(f-B);
            visited[f-B] = visited[f] + 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S >> D >> F >> B >> K;

    int police;
    for (int i = 0; i < K; i++)
    {
        cin >> police;

        visited[police] = -1;
    }

    bfs(S);

    if (visited[D])
        cout << visited[D] - 1;
    else
        cout << "BUG FOUND";
}
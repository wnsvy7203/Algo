// 

#include <iostream>
#include <queue>

#define MAX 100001

using namespace std;

int N, M, A, B;
int visited[MAX];

queue<int> que;

void bfs()
{
    que.push(0);
    visited[0] = 1;

    while (!que.empty())
    {
        int f = que.front();
        que.pop();

        if (f == N)
            break;

        if (f+A < MAX && !visited[f+A])
        {
            que.push(f+A);
            visited[f+A] = visited[f] + 1;
        }

        if (f+B < MAX && !visited[f+B])
        {
            que.push(f+B);
            visited[f+B] = visited[f] + 1;
        }
    }

    cout << visited[N]-1;
}

int main()
{
    cin >> N >> M >> A >> B;

    int L, R;
    while (M--)
    {
        cin >> L >> R;

        for (int i = L; i <= R; i++)
            visited[i] = -1;
    }

    bfs();
}
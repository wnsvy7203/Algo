#include <iostream>
#include <queue>

using namespace std;

int N;
int miro[1001];
int visited[1001];

queue<int> que;

void bfs()
{
    while (!que.empty())
    {
        int front = que.front();
        que.pop();

        for (int i = 1; i <= miro[front]; i++)
            if (front+i <= 1000 && !visited[front+i])
            {
                que.push(front+i);
                visited[front+i] = visited[front] + 1;
            }
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> miro[i];
    
    que.push(0);
    visited[0] = 1;

    bfs();

    cout << visited[N-1] - 1;
}
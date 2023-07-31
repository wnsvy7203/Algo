// 12ms

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<int> graph[20001];
int visited[20001];

queue<int> que;

void bfs()
{
    que.push(1);
    visited[1] = 1;

    while (!que.empty())
    {
        int q = que.front();
        int cnt = que.front();

        que.pop();
        
        for (int i = 0; i < graph[q].size(); i++)
            if (!visited[graph[q][i]])
            {
                que.push(graph[q][i]);
                visited[graph[q][i]] = visited[q] + 1;
            }
    }


    int ans1 = 0;
    int ans2 = *max_element(visited+1, visited+N+1);
    int ans3 = 0;

    for (int i = N; i >= 1; i--)
        if (visited[i] == ans2)
        {
            ans1 = i;
            ans3++;
        }
    
    cout << ans1 << ' ' << ans2-1 << ' ' << ans3;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int A_i, B_i;

    while (M--)
    {
        cin >> A_i >> B_i;

        graph[A_i].push_back(B_i);
        graph[B_i].push_back(A_i);
    }

    bfs();
}
// 36ms

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, K;
int nums[1001];

queue<pair<int, int>> que;
bool visited[50001];

void bfs()
{
    while (!que.empty())
    {
        int f = que.front().first;
        int cnt = que.front().second;
        que.pop();

        if (cnt > K)
            continue;
        
        visited[f] = 1;
        
        for (int i = 0; i < N; i++)
            if (!visited[f + nums[i]])
                que.push({f + nums[i], cnt+1});
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> nums[i];

    cin >> K;

    for (int i = 0; i < N; i++)
    {
        que.push({nums[i], 1});
        visited[nums[i]] = 1;
    }

    bfs();

    for (int i = 1; i < 50001; i++)
        if (!visited[i])
            if (i % 2)
            {
                cout << "jjaksoon win at " << i;
                return 0;
            }
            else
            {
                cout << "holsoon win at " << i;
                return 0;
            }
}
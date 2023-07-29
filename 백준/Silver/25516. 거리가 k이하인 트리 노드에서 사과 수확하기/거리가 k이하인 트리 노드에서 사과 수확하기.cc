// 92ms

#include <iostream>
#include <queue>

using namespace std;

int n, k;
vector<int> graph[100001];
int tree[100001];

queue<pair<int, int>> que;
bool visited[100001];

int bfs()
{
    que.push({0, 0});

    int cnt = 0;

    while (!que.empty())
    {
        int f = que.front().first;
        int dist = que.front().second;

        visited[f] = 1;
        que.pop();

        if (tree[f] == 1 && dist <= k)
            cnt++;
        
        for (int i = 0; i < graph[f].size(); i++)
            if (!visited[graph[f][i]])
                que.push({graph[f][i], dist+1});
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    int p, c;

    for (int i = 0; i < n-1; i++)
    {
        cin >> p >> c;

        graph[p].push_back(c);
    }

    for (int i = 0; i < n; i++)
        cin >> tree[i];

    cout << bfs();
}
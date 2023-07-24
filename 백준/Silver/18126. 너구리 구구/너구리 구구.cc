// 96ms

#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int N, A, B, C;
bool visited[5001];
long long int dist[5001];

vector<pair<int, int>> graph[5001];
queue<pair<int, long long int>> que;


void bfs()
{
    que.push({1, 0});

    while (!que.empty())
    {
        int daum = que.front().first;
        long long int tmp = que.front().second;

        que.pop();

        visited[daum] = 1;

        for (int i = 0; i < graph[daum].size(); i++)
            if (!visited[graph[daum][i].first])
            {
                que.push({graph[daum][i].first, tmp+graph[daum][i].second});
                dist[graph[daum][i].first] = tmp+graph[daum][i].second;
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    for (int i = 0; i < N-1; i++)
    {
        cin >> A >> B >> C;

        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    bfs();

    cout << *max_element(dist+1, dist+N+1);
}
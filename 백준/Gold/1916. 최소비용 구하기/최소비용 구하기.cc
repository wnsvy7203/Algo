// 그래프 알고리즘에서 최소 비용을 구하는 경우 사용할 수 있는 대표적 알고리즘
// 다익스트라, 벨만-포드, 플로이드-워샬 알고리즘
// 다익스트라는 최소 비용 중에서도, 주어진 두 노드(시작 -> 도착) 사이의 최소 비용 경로를 찾을 때 유용

// 동작 원리
// 1. 시작 노드와 직접적으로 연결된 모든 정점들의 거리를 비교해서 업데이트 -> 시작 노드 방문 체크
// 2. 방문한 정점들과 연결된 정점들 중 비용이 가장 적게 드는 정점을 선택, 방문 체크
// 3. 2번 과정에서 갱신될 수 있는 정점들의 거리를 갱신시켜준다.
// 4. 2 ~ 3번 과정 반복

#include <iostream>
#include <vector>
#include <queue>

#define INF 100'000'001

using namespace std;

int N, M, S, E;
vector<pair<int, int>> graph[1001];
bool visited[1001];
int dist[1001];

void dijkstra()
{
    fill_n(&dist[0], 1001, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({0, S});
    dist[S] = 0;

    while (!que.empty())
    {
        int cost = que.top().first;
        int node = que.top().second;
        que.pop();

        if (dist[node] < cost)
            continue;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int next_node = graph[node][i].first;
            int next_cost = graph[node][i].second;

            if (dist[next_node] > cost + next_cost)
            {
                dist[next_node] = cost + next_cost;
                que.push({dist[next_node], next_node});
            }
        }
    }

    cout << dist[E];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    while (M--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    cin >> S >> E;

    dijkstra();
}
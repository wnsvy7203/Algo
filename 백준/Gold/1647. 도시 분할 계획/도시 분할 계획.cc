// 프림 알고리즘
// 48ms

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, ans, del;
vector<pair<int, int>> edges[100001];
void init()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        edges[from].push_back({cost, to});
        edges[to].push_back({cost, from});
    }
}

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pque;
bool visited[100001];
void prim()
{
    // 1번 정점을 시작점으로 선택
    pque.push({0, 1});
    while (!pque.empty())
    {
        int cost = pque.top().first;
        int node = pque.top().second;
        pque.pop();

        // 이미 방문한 정점의 경우 스킵
        if (visited[node])
            continue;
        
        // 정점 방문 처리
        visited[node] = 1;
        ans += cost;
        del = max(del, cost);

        // 연결된 간선을 우선순위 큐에 추가
        for (int i = 0; i < edges[node].size(); i++)
        {
            int next_cost = edges[node][i].first;
            int next_node = edges[node][i].second;

            if (!visited[next_node])
                pque.push({next_cost, next_node});
        }
    }
    
    cout << ans-del;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    init();
    prim();
}
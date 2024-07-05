#include <iostream>
#include <vector>
#include <queue>

#define INF 200'000'000'000'000

using namespace std;

int N, M, X, Y, Z;
vector<pair<int, int>> graph[100001];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pque;
long long dist[100001];

long long dijkstra(int s, int e, int skip) {
    fill_n(&dist[0], 100001, INF);
    pque.push({0, s});
    dist[s] = 0;

    while (!pque.empty()) {
        long long cost = pque.top().first;
        int node = pque.top().second;
        pque.pop();

        if (dist[node] < cost)
            continue;

        if (node == skip)
            continue;

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_cost = graph[node][i].second;

            if (dist[next_node] > cost + next_cost) {
                dist[next_node] = cost + next_cost;
                pque.push({dist[next_node], next_node});
            }
        }
    }

    return dist[e];
}

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    cin >> X >> Y >> Z;
}

long long ans1, ans2;
void find_answer() {
    ans1 += dijkstra(X, Y, 0);
    ans1 += dijkstra(Y, Z, 0);
    ans2 = dijkstra(X, Z, Y);

    cout << (ans1 >= INF ? -1 : ans1) << ' ' << (ans2 >= INF ? -1 : ans2);
}

int main() {
    init();
    find_answer();
}

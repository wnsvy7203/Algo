// 벨만-포드
// 그래프에서 최소 비용을 구할 수 있는 알고리즘
// 다익스트라보다는 시간이 더 오래 걸린다.
// 모든 경우의 수를 다 탐색해 가면서 최소 비용을 탐색


#include <iostream>
#include <vector>
#include <tuple>

#define INF 500 * 10000

using namespace std;

int TC, N, M, W;
int dist[501];
vector<tuple<int, int, int>> graph;

bool Bellman_Ford()
{
    fill_n(&dist[1], 500, INF);
    dist[1] = 0;

    for (int i = 1; i < N; i++)
        for (int j = 0; j < graph.size(); j++)
        {
            int from = get<0>(graph[j]);
            int to = get<1>(graph[j]);
            int cost = get<2>(graph[j]);
            
            if (dist[to] > dist[from] + cost)
                dist[to] = dist[from] + cost;
        }
    
    for (int i = 0; i < graph.size(); i++)
    {
        int from = get<0>(graph[i]);
        int to = get<1>(graph[i]);
        int cost = get<2>(graph[i]);
        
        if (dist[to] > dist[from] + cost)
            return 1;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> TC;
    while (TC--)
    {
        graph.clear();

        cin >> N >> M >> W;
        while (M--)
        {
            int S, E, T;
            cin >> S >> E >> T;

            graph.push_back({S, E, T});
            graph.push_back({E, S, T});
        }

        while (W--)
        {
            int S, E, T;
            cin >> S >> E >> T;

            graph.push_back({S, E, -T});
        }

        bool flag = Bellman_Ford();
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
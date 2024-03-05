#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, K, M, P;
int degree[1001];
vector<int> graph[1001];
queue<int> que;

void topology_sort()
{
    vector<pair<int, int>> strahler;
    for (int i = 0; i <= M; i++)
        strahler.push_back({1, 0});

    while (!que.empty())
    {
        int node = que.front();
        que.pop();

        for (int i = 0; i < graph[node].size(); i++)
        {
            int next_node = graph[node][i];
            degree[next_node]--;

            if (!degree[next_node])
                que.push(next_node);

            if (strahler[next_node].first < strahler[node].first)
            {
                strahler[next_node].first = strahler[node].first;
                strahler[next_node].second = 1;
            }
            else if (strahler[next_node].first == strahler[node].first)
            {
                strahler[next_node].second++;

                if (strahler[next_node].second == 2)
                    strahler[next_node].first++;
            }
        }
    }

    cout << strahler[M].first << '\n';
}

void init()
{
    cin >> T;
    while (T--)
    {
        cin >> K >> M >> P;
        cout << K << ' ';

        fill_n(&degree[1], 1000, 0);
        for (int i = 1; i <= M; i++)
            graph[i].clear();

        while (P--)
        {
            int A, B;
            cin >> A >> B;
            graph[A].push_back(B);
            degree[B]++;
        }

        for (int i = 1; i <= M; i++)
            if (!degree[i])
                que.push(i);

        topology_sort();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
}

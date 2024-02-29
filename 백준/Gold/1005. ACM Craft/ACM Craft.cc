#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// T: test case 개수, N: 건물의 개수, K: 규칙의 개수, W: 건설해야 할 건물의 번호
int T, N, K, W;
int D[1001];
int degree[1001];
vector<int> graph[1001];


queue<int> que;
void topology_sort()
{
    int res[1001];

    for (int i = 1; i <= N; i++)
        res[i] = D[i];

    for (int i = 1; i <= N; i++)
        if (!degree[i])
            que.push(i);

    while (!que.empty())
    {
        int node = que.front();
        que.pop();

        for (int j = 0; j < graph[node].size(); j++)
        {
            int next = graph[node][j];
            res[next] = max(res[next], res[node] + D[next]);

            degree[next]--;

            if (!degree[next])
                que.push(next);
        }

    }

    cout << res[W] << '\n';
}

void init()
{
    cin >> T;
    while (T--)
    {
        fill_n(&degree[0], 1001, 0);

        cin >> N >> K;
        for (int i = 1; i <= N; i++)
        {
            cin >> D[i];
            graph[i].clear();
        }

        while (K--)
        {
            int X, Y;
            cin >> X >> Y;
            graph[X].push_back(Y);
            degree[Y]++;
        }

        cin >> W;
        topology_sort();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
}

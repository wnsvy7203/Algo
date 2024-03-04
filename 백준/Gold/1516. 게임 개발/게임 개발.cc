#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int degree[501], building_time[501], dp[501];
vector<int> graph[501];
queue<int> que;

void init()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> building_time[i];
        dp[i] = building_time[i];

        int num = 0;
        while (1)
        {
            cin >> num;
            if (num == -1)
                break;

            graph[num].push_back(i);
            degree[i]++;
        }
    }

    for (int i = 1; i <= N; i++)
        if (!degree[i])
            que.push(i);
}

void topology_sort()
{
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

            dp[next_node] = max(dp[next_node], dp[node] + building_time[next_node]);
        }
    }
}

void find_answer()
{
    for (int i = 1; i <= N; i++)
        cout << dp[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    topology_sort();
    find_answer();
}

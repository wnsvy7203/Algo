#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int degree[32001];
vector<int> graph[32001];
queue<int> que;

void init()
{
    cin >> N >> M;
    while (M--)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        degree[B]++;
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

        cout << node << ' ';

        for (int i = 0; i < graph[node].size(); i++)
        {
            int next = graph[node][i];
            degree[next]--;

            if (!degree[next])
                que.push(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    topology_sort();
}
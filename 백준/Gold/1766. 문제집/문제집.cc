#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001

using namespace std;

int N, M, cnt;
int degree[MAX];
vector<int> graph[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pque;

void topology_sort()
{
    while (!pque.empty())
    {
        int c = pque.top().first;
        int node = pque.top().second;
        pque.pop();

        cout << node << ' ';

        for (int i = 0; i < graph[node].size(); i++)
        {
            int next_node = graph[node][i];
            degree[next_node]--;

            if (!degree[next_node])
                pque.push({c, next_node});
        }
    }
}

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
    {
        if (!degree[i])
        {
            pque.push({cnt, i});
            cnt++;
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
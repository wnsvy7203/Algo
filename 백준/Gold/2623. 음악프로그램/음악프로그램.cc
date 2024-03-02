#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
bool visited[1001];
int degree[1001];
vector<int> graph[1001], answer;
queue<int> que;
void init()
{
    cin >> N >> M;
    while (M--)
    {
        int cnt;
        cin >> cnt;

        int one;
        cin >> one;
        for (int i = 1; i < cnt; i++)
        {
            int two;
            cin >> two;
            degree[two]++;
            graph[one].push_back(two);

            one = two;
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

        if (visited[node])
            return;
        else
            answer.push_back(node);

        for (int i = 0; i < graph[node].size(); i++)
        {
            int next_node = graph[node][i];
            degree[next_node]--;

            if (!degree[next_node])
                que.push(next_node);
        }
    }
}

void find_answer()
{
    if (answer.size() != N)
        cout << 0;
    else
        for (int num : answer)
            cout << num << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    topology_sort();
    find_answer();
}
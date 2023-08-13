// 108ms

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;

vector<int> graph[26];
bool visited[26];


void bfs(int s, int e)
{
    memset(visited, 0, sizeof(visited));
    queue<int> que;
    que.push(s);
    visited[s] = 1;


    while (!que.empty())
    {
        int f = que.front();
        que.pop();

        if (f == e)
        {
            cout << 'T';
            return;
        }

        for (int i = 0; i < graph[f].size(); i++)
            if (!visited[graph[f][i]])
            {
                visited[graph[f][i]] = 1;
                que.push(graph[f][i]);
            }
    }

    cout << 'F';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    char s, e;
    string is;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> is >> e;

        graph[s-97].push_back(e-97);
    }

    cin >> m;

    while (m--)
    {
        cin >> s >> is >> e;
        bfs(s-97, e-97);
        cout << '\n';
    }
}
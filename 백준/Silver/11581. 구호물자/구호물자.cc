//

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> graph[101];
bool visited[101];
bool check[101];

bool flag = 0;

void dfs(int r)
{
    visited[r] = 1;

    for (int x : graph[r])
    {
        if (check[x])
            return;

        if (!visited[x])
            dfs(x);
        else
        {
            flag = 1;
        }
    }
    check[r] = 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    int M;
    for (int i = 1; i < N; i++)
    {
        cin >> M;

        int num;
        while (M--)
        {
            cin >> num;
            graph[i].push_back(num);
        }
    }

    dfs(1);

    if (flag)
        cout << "CYCLE";
    else
        cout << "NO CYCLE";
}
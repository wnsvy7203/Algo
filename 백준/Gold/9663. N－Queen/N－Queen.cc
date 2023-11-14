#include <iostream>

using namespace std;

int N, ans;
int visited[15];

bool flag(int v)
{
    for (int i = 0; i < v; i++)
        if (visited[v] == visited[i] || abs(visited[v] - visited[i]) == abs(v-i))
            return 0;
    
    return 1;
}

void dfs(int depth)
{
    if (depth == N)
    {
        ans++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        visited[depth] = i;

        if (flag(depth))
            dfs(depth+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    dfs(0);

    cout << ans;
}
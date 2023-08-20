//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define MAX 100001

using namespace std;

int N, M, R;
vector<int> E[MAX];

long long int t[MAX];
long long int d[MAX];
long long int td[MAX];

int cnt = 0;
void dfs(int r, int depth)
{
    cnt++;
    t[r] = cnt;
    d[r] = depth;

    for (int x : E[r])
        if (!t[x])
            dfs(x, depth+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> R;

    int u, v;
    while (M--)
    {
        cin >> u >> v;

        E[u].push_back(v);
        E[v].push_back(u);
    }
    
    for (int i = 1; i <= N; i++)
        sort(E[i].begin(), E[i].end(), greater<>());

    dfs(R, 1);

    for (int i = 1; i <= N; i++)
        td[i] = t[i] * (d[i]-1);

    cout << accumulate(td+1, td+N+1, 0LL);
}
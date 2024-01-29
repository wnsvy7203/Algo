#include <iostream>

using namespace std;

int n, m;
int par[501];

int find(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = find(par[x]);
}

void union_sets(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x > y)
        swap(x, y);

    if (x == y)
        par[y] = 0;
    else
        par[y] = x;
}

int tc = 0;
void find_answer()
{
    tc++;
    int T = 0;

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        union_sets(u, v);
    }

    for (int i = 1; i <= n; i++)
        if (par[i] == i)
            T++;

    cout << "Case " << tc << ": ";
    if (!T)
        cout << "No trees.\n";
    else if (T == 1)
        cout << "There is one tree.\n";
    else
        cout << "A forest of " << T << " trees.\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1)
    {
        cin >> n >> m;
        if (!n && !m)
            return 0;

        for (int i = 1; i <= n; i++)
            par[i] = i;

        find_answer();
    }
}
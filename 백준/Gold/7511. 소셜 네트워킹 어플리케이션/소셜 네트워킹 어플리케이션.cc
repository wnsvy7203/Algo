#include <iostream>

using namespace std;

int T, n, k, m;
int par[1000000];

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

    par[y] = x;
}

void find_answer()
{
    cin >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        
        u = find(u);
        v = find(v);

        if (u == v)
            cout << "1\n";
        else
            cout << "0\n";
    }
    cout << '\n';
}

void init()
{
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Scenario " << i << ":\n";

        cin >> n;
        for (int i = 1; i <= n; i++)
            par[i] = i;

        cin >> k;
        while (k--)
        {
            int a, b;
            cin >> a >> b;
            union_sets(a, b);
        }
            
        find_answer();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
}
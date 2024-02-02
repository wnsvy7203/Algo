#include <iostream>

using namespace std;

int n, m;
int par[1000001];

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

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        par[i] = i;
}

void find_answer()
{
    while (m--)
    {
        bool flag;
        int a, b;

        cin >> flag >> a >> b;
        
        if (!flag)
            union_sets(a, b);
        else
        {
            a = find(a);
            b = find(b);

            if (a == b)
                cout << "YES\n";
            else
                cout << "NO\n";
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    find_answer();
}
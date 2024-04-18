#include <iostream>

using namespace std;

int G, P, g[100001], par[100001];

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
    cin >> G >> P;
    for (int i = 1; i <= G; i++)
        par[i] = i;

    for (int i = 1; i <= P; i++)
        cin >> g[i];
}

int ans;
void find_answer()
{
    for (int i = 1; i <= P; i++)
    {
        int a = find(g[i]);
        if (!a)
            break;

        union_sets(a, a-1);
        ans++;
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    find_answer();
}
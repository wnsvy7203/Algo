#include <iostream>

using namespace std;

int N;
int par[300001];

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
    cin >> N;
    for (int i = 1; i <= N; i++)
        par[i] = i;
    
    for (int i = 0; i < N-2; i++)
    {
        int a, b;
        cin >> a >> b;
        union_sets(a, b);
    }
}

void find_answer()
{
    for (int i = 1; i <= N; i++)
        if (par[i] == i)
            cout << i << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    find_answer();
}
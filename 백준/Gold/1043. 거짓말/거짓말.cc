#include <iostream>
#include <vector>

using namespace std;

int N, M, K, ans;
bool known[51];
int par[51];
vector<int> party[51];

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
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        par[i] = i;

    cin >> K;
    while (K--)
    {
        int num;
        cin >> num;
        known[num] = 1;
    }
}

void settings()
{
    for (int i = 0; i < M; i++)
    {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            int num;
            cin >> num;
            party[i].push_back(num);
        }

        for (int j = 0; j < party[i].size()-1; j++)
            union_sets(party[i][j], party[i][j+1]);
    }
}

void find_answer()
{
    for (int i = 1; i <= N; i++)
    {
        if (known[i])
        {
            int num = find(i);
            known[num] = 1;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x = find(party[i][0]);
        if (par[x] == x && !known[x])
            ans++;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    settings();
    find_answer();
}
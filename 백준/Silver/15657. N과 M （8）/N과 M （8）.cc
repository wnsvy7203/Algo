#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
int perm[8];

void dfs(int idx, int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
            cout << perm[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = idx; i < N; i++)
    {
        perm[depth] = v[i];
        dfs(i, depth+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    dfs(0, 0);
}
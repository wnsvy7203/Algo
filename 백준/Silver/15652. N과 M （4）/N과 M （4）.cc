#include <iostream>
#include <vector>

using namespace std;

int N, M;
int nums[8];
int comb[8];

void dfs(int idx, int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
            cout << comb[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i = idx; i < N; i++)
    {
        comb[depth] = nums[i];
        dfs(i, depth+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        nums[i] = i+1;
    
    dfs(0, 0);
}
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int nums[8], perm[8];

void dfs(int idx, int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
            cout << perm[i] << ' ';
        cout << '\n';
        return;
    }

    int tmp = 0;
    for (int i = idx; i < N; i++)
    {
        if (tmp != nums[i])
        {
            perm[depth] = nums[i];
            tmp = nums[i];

            dfs(i, depth+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    
    sort(nums, nums+N);

    dfs(0, 0);
}
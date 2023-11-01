//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int nums[8], perm[8];
bool visited[8];

void dfs(int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
            cout << perm[i] << ' ';
        cout << '\n';
        return;
    }

    int tmp = 0;
    for (int i = 0; i < N; i++)
        if (!visited[i] && tmp != nums[i])
        {
            perm[depth] = nums[i];
            tmp = nums[i];

            visited[i] = 1;
            dfs(depth+1);
            visited[i] = 0;
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

    dfs(0);
}
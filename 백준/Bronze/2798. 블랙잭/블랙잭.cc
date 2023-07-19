// Bronze 2. Blackjack
// 24ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int nums[101];
bool visited[101];

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> nums[i];

    for (int i = N-3; i < N; i++)
        visited[i] = 1;

    int ans = 0;

    do
    {
        int sum = 0;

        for (int i = 0; i < N; i++)
            if (visited[i])
                sum += nums[i];

        if (sum <= M)
            if (ans < sum)
                ans = sum;
    }
    while(next_permutation(visited, visited+N));

    cout << ans;
}
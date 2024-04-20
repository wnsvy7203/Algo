#include <iostream>
#include <map>

using namespace std;

int N, S;
int nums[40];
map<int, int> m;
long long ans;

void left(int s, int sum)
{
    if (s == N/2)
    {
        m[sum]++;
        return;
    }

    left(s+1, sum);
    left(s+1, sum + nums[s]);
}

void right(int s, int sum)
{
    if (s == N)
    {
        ans += m[S-sum];
        return;
    }

    right(s+1, sum);
    right(s+1, sum + nums[s]);
}

void find_answer()
{
    if (S)
        cout << ans;
    else
        cout << ans-1;
}

void init()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> nums[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    left(0, 0);
    right(N/2, 0);
    find_answer();
}
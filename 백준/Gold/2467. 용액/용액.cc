#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int nums[100000];
void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> nums[i];
}

pair<int, int> ans;
void two_pointer()
{
    int s = 0;
    int e = N-1;
    int comp = 2e9;

    while (s < e)
    {
        int sum = nums[s] + nums[e];

        if (abs(comp) > abs(sum))
        {
            comp = sum;
            ans.first = nums[s];
            ans.second = nums[e];
        }

        if (sum < 0)
            s++;
        else if (sum > 0)
            e--;
        else
            break;
        
    }

    cout << ans.first << ' ' << ans.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    two_pointer();
}
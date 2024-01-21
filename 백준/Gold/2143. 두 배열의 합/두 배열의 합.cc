#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, n, m;
int A[1000], B[1000];
vector<int> res1, res2;

void input()
{
    cin >> T;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> B[i];
}

long long ans;
void find_answer()
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += A[j];
            res1.push_back(sum);
        }
    }

    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = i; j < m; j++)
        {
            sum += B[j];
            res2.push_back(sum);
        }
    }

    sort(res2.begin(), res2.end());
    for (int it : res1)
    {
        int u = upper_bound(res2.begin(), res2.end(), T-it) - res2.begin();
        int l = lower_bound(res2.begin(), res2.end(), T-it) - res2.begin();

        ans += (u-l);
    }
    
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    find_answer();
}
// 최댓값을 만들어내는 구간이 여러 개인 경우, 개수가 더 적은 쪽이 우선.
// 개수마저 같은 경우에는 인덱스가 앞서는 구간을 답으로

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000001

using namespace std;

int n;
int L[1001];
long long dp[1001][1001];
long long ans;
vector<pair<int, int>> idx;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> L[i];
        for (int j = 1; j <= L[i]; j++)
        {
            int num;
            cin >> num;
            dp[i][j] = dp[i][j-1] + num;
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        int tmp = -MAX;
        int sidx = 1;
        int eidx = 0;
        for (int j = 1; j <= L[i]; j++)
            for (int k = j; k <= L[i]; k++)
            {
                int cur = dp[i][k] - dp[i][j-1];
                if (tmp < cur)
                {
                    tmp = cur;
                    sidx = j;
                    eidx = k;
                }
                else if (tmp == cur)
                    if ((eidx - sidx) > (k - j))
                    {
                        sidx = j;
                        eidx = k;
                    }
            }
        ans += tmp;
        idx.push_back({sidx, eidx});
    }

    cout << ans << '\n';
    for (pair<int, int> p : idx)
        cout << p.first << ' ' << p.second << '\n';
}
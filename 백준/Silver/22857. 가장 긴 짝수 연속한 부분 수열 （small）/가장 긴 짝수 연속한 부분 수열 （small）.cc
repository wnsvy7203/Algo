//

#include <iostream>

using namespace std;

int N, K;
int S[50001];

int cal(int cnt, int idx)
{
    int res = 0;

    for (int i = idx; i <= N; i++)
        if (!(S[i] % 2))
            res++;
        else if (cnt)
        {
            cnt--;
            continue;
        }
        else
            break;

    return res;
}

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> S[i];
    
    int ans = 0;
    for (int i = 1; i <= N; i++)
        if (!(S[i] % 2))
            ans = max(ans, cal(K, i));

    cout << ans;
}
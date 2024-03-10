#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 300000

using namespace std;

int N, K;
vector<pair<int, int>> MV(MAX);
vector<int> C(MAX);
priority_queue<int, vector<int>> pque;

void init()
{
    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> MV[i].first >> MV[i].second;

    for (int i = 0; i < K; i++)
        cin >> C[i];

    sort(MV.begin(), MV.begin()+N);
    sort(C.begin(), C.begin()+K);
}

void find_answer()
{
    int idx = 0;
    long long ans = 0;
    for (int i = 0; i < K; i++)
    {
        while (idx < N && C[i] >= MV[idx].first)
        {
            pque.push(MV[idx].second);
            idx++;
        }

        if (!pque.empty())
        {
            ans += pque.top();
            pque.pop();
        }
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    find_answer();
}

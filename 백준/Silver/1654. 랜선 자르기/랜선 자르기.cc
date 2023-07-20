// Silver 2. Cutting LAN Line

#include <iostream>
#include <algorithm>

using namespace std;

int K, N;
int lan[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;

    for (int i = 0; i < K; i++)
        cin >> lan[i];
    
    sort(lan, lan+K, greater<>());

    unsigned int start = 1;
    unsigned int end = lan[0];

    while (start <= end)
    {
        unsigned int mid = (start + end) / 2;

        unsigned int cnt = 0;

        for (int i = 0; i < K; i++)
            cnt += lan[i] / mid;
        
        if (cnt < N)
            end = mid - 1;
        else
            start = mid + 1;
    }

    cout << end;
}
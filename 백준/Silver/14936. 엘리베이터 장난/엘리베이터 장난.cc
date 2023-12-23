#include <iostream>

using namespace std;

int N, m;

// 아무것도 하지 않는 경우가 있으므로 ans는 최소 1
int ans = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> m;

    // case 1. 모든 버튼
    // 1 2 3 4 5 6 7
    int c1 = N;
    if (c1 <= m)
        ans++;

    // case 2. 짝수 버튼
    //   2   4   6
    int c2 = N/2;
    if (c1 >= 2 && c2 <= m)
        ans++;

    // case 3. 홀수 버튼
    // 1   3   5   7
    int c3 = (N+1)/2;
    if (c1 >= 3 && c3 <= m)
        ans++;

    // case 4. 3k+1 버튼
    // 1     4     7
    int c4 = (N-1)/3 + 1;
    if (c1 >= 2 && c4 <= m)
        ans++;
    
    // case 1 + case 2 => case 3
    // case 1 + case 3 => case 2
    // case 1 + case 4
    if (c1 >= 3 && c1 + c4 <= m)
        ans++;
    
    // case 2 + case 3 => case 1
    // case 2 + case 4
    if (c1 >= 3 && c2 + c4 <= m)
        ans++;
    
    // case 3 + case 4
    if (c1 >= 3 && c3 + c4 <= m)
        ans++;

    // case 1 + case 2 + case 3 => 0
    // case 1 + case 2 + case 4 => case 3 + case 4
    // case 1 + case 3 + case 4 => case 2 + case 4
    // case 2 + case 3 + case 4 => case 1 + case 4
    // case 1 + case 2 + case 3 + case 4 => case 4

    cout << ans;
}
// 516ms

#include <iostream>

#define MAX 100001

using namespace std;

int T, n, ans;
int arr[MAX];
bool visited1[MAX], visited2[MAX];

void dfs(int idx)
{
    visited1[idx] = 1;

    int next = arr[idx];
    if (!visited1[next])
        dfs(next);
    else if (!visited2[next])
    {
        ans++;

        for (int i = next; i != idx; i = arr[i])
            ans++;
    }
    
    visited2[idx] = 1;
}

void find_answer()
{
    ans = 0;
    for (int i = 1; i <= n; i++)
        if (!visited1[i])
            dfs(i);

    cout << n - ans << '\n';
}

void init()
{
    cin >> T;
    while (T--)
    {
        fill_n(&arr[0], MAX, 0);
        fill_n(&visited1[0], MAX, false);
        fill_n(&visited2[0], MAX, false);

        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        find_answer();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
}
// Silver 5. Sorting Coordinates 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
pair<int, int> dots[100001];

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> dots[i].first >> dots[i].second;

    sort(dots, dots+N, comp);

    for (int i = 0; i < N; i++)
        cout << dots[i].first << ' ' << dots[i].second << '\n';
}

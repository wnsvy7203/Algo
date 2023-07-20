#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
pair<int, int> dots[100001];

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> dots[i].first >> dots[i].second;

    sort(dots, dots+N, comp);

    for (int i = 0; i < N; i++)
    {
        cout << dots[i].first << ' ' << dots[i].second << '\n';
    }
}
// 92ms

#include <iostream>
#include <algorithm>

using namespace std;

string arr[20001];

bool compare(string a, string b)
{
    if (a.length() != b.length())
        return a.length() < b.length();
    else
        return a < b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;

    string word;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr+N, compare);

    for (int i = 0; i < N; i++)
    {
        if (i && arr[i] == arr[i-1])
            continue;

        cout << arr[i] << '\n';
    }
}
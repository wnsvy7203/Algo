#include <iostream>

using namespace std;

int main()
{
    int N, X;
    int arr[10005];

    cin >> N >> X;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (arr[i] < X)
        {
            cout << arr[i] << " ";
        }
    }
}
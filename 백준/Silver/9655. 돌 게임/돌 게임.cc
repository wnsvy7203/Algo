// 

#include <iostream>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    if (N % 2)
        cout << "SK";
    else
        cout << "CY";
}
#include <iostream>

using namespace std;

int N;
long long coord[10000][2];

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> coord[i][0] >> coord[i][1];
}

void shoelace()
{
    long long sum1 = coord[N-1][0] * coord[0][1];
    long long sum2 = coord[N-1][1] * coord[0][0];

    for (int i = 0; i < N-1; i++)
    {
        sum1 += (coord[i][0] * coord[i+1][1]);
        sum2 += (coord[i][1] * coord[i+1][0]);
    }

    double ans = abs(sum1 - sum2);
    cout.precision(1);
    cout << fixed << ans / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    shoelace();
}
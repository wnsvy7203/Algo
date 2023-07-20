#include <iostream>
#include <algorithm>

using namespace std;

int N;
int S[51][2];

int main()
{
    cin >> N;

    int x, y;

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;

        S[i][0] = x;
        S[i][1] = y;
    }

    for (int i = 0; i < N; i++)
    {
        int rank = 1;

        for (int j = 0; j < N; j++)
        {
            if (S[i][0] < S[j][0] && S[i][1] < S[j][1])
                rank++;
        }
        
        cout << rank << ' ';
    }
}
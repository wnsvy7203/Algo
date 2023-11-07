#include <iostream>

using namespace std;

int N;
long long B;
long long A[5][5], tmp[5][5], ans[5][5];

void mul(long long X[5][5], long long Y[5][5])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            tmp[i][j] = 0;
            for (int k = 0; k < N; k++)
                tmp[i][j] += (X[i][k] * Y[k][j]);
            
            tmp[i][j] %= 1000;
        }
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            X[i][j] = tmp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> B;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
        ans[i][i] = 1;
    }

    while (B > 0)
    {
        if (B % 2)
            mul(ans, A);
        mul(A, A);
        B /= 2;
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << ans[i][j] << ' ';
        
        cout << '\n';
    }
}
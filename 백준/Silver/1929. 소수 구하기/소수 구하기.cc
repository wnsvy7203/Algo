// Silver 3. Finding Prime Numbers
// 20ms

#include <iostream>
#include <vector>
#include <cmath>
#define MAX 1000001

using namespace std;

int M, N;
bool prime[MAX];

void eratos()
{
    for (int i = 2; i < MAX; i++)
        if (prime[i])
            for (int j = 2*i; j < MAX; j += i)
                prime[j] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(prime+2, prime+MAX, 1);
    eratos();

    cin >> M >> N;

    for (int i = M; i <= N; i++)
        if (prime[i])
            cout << i << '\n';
}
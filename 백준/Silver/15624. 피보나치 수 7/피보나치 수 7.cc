//

#include <iostream>

#define MAX 1000001
#define DIV 1000000007

using namespace std;

int n;
int fibo[MAX];

int main()
{
    fibo[1] = 1;

    for (int i = 2; i < MAX; i++)
        fibo[i] = (fibo[i-1] + fibo[i-2]) % DIV;

    cin >> n;

    cout << fibo[n];
}
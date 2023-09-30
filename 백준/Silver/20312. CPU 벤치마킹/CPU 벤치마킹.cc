//

#include <iostream>
#include <vector>

#define MAX 500001
#define DIV 1000000007

using namespace std;

int N;
int ratio[MAX];

int main()
{
    cin >> N;
    for (int i = 1; i < N; i++)
        cin >> ratio[i];

    long long ans = 0;
    long long tmp = 0;
    for (int i = 1; i < N; i++)
    {
        tmp = ((tmp+1) * ratio[i]) % DIV;
        ans = (ans + tmp) % DIV;
    }

    cout << ans;
}
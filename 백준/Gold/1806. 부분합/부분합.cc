#include <iostream>

#define MAX 100000

using namespace std;

int N, S;
int arr[MAX];
void input()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
}

int s, e;
int ans = MAX;
void two_pointer()
{
    int sum = 0;
    while (e < N)
    {
        sum += arr[e];
        
        while (sum >= S)
        {
            ans = min(ans, e-s+1);
            sum -= arr[s];
            s++;
        }

        e++;
    }

    if (ans == MAX)
        cout << 0;
    else
        cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    two_pointer();
}
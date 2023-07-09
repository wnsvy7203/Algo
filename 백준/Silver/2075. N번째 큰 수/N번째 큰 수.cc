// Silver 2. Nth Largest Number

#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 2250000

using namespace std;

int N;
int nums[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;    

    for (int i = 0; i < N*N; i++)
        cin >> nums[i];

    sort(nums, nums+N*N, greater<>());

    cout << nums[N-1];
}
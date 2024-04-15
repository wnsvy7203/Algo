#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000000

using namespace std;

int N, A[MAX];
vector<int> LIS;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        
        if (!i)
            LIS.push_back(A[i]);
        else if (LIS[LIS.size()-1] < A[i])
            LIS.push_back(A[i]);
        else
        {
            // LIS 배열에서 자기 자신보다 크거나 같은 값을 찾고, 해당 idx를 자기 자신으로 바꿔준다.
            int idx = lower_bound(LIS.begin(), LIS.end(), A[i]) - LIS.begin();
            LIS[idx] = A[i];
        }
    }

    cout << LIS.size();
}
// Bronze 2. Sorting Numbers

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<int> nums;

    for (int i = 0; i < N; i++)
    {
        int num;

        cin >> num;

        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < N; i++)
    {
        cout << nums[i] << '\n';
    }
}
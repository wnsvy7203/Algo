//

#include <iostream>

using namespace std;

string A, B;
int nums[16];

int main()
{
    cin >> A >> B;

    for (int i = 0; i < 8; i++)
    {
        nums[i*2] = A[i] - 48;
        nums[i*2+1] = B[i] - 48;
    }

    int cnt = 15;
    while (cnt >= 2)
    {
        for (int i = 0; i < cnt; i++)
            nums[i] = (nums[i] + nums[i+1]) % 10;

        cnt--;
    }
    cout << nums[0] << nums[1];
}
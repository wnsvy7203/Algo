#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int nums[1000];

int solution(vector<int> array) {
    for (int i = 0; i < array.size(); i++)
        nums[array[i]]++;
    
    int ans = 0, idx = 0;
    for (int i = 0; i < 1000; i++)
        if (ans < nums[i])
        {
            ans = nums[i];
            idx = i;
        }
        
    bool flag = 0;
    for (int i = 0; i < 1000; i++)
        if (ans == nums[i] && idx != i)
        {
            flag = 1;
            break;
        }
            
    if (flag)
        return -1;
    else
        return idx;
}
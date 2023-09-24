#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    sort(array.begin(), array.end());
    
    int tmp = 100;
    int ans = 0;
    
    for (int i : array)
        if (tmp > abs(i-n))
        {
            tmp = abs(i-n);
            ans = i;
        }
    return ans;
}
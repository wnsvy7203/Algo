#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ans;

bool cmp(vector<int> a, vector<int> b)
{
    if (a[0] == b[0])
        return a[0] < b[0];

    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), cmp);
    
    int now = 0;
    
    for (vector<int> target : targets)
    {
        int s = target[0];
        int e = target[1];
        
        if (now <= s)
        {
            ans++;
            now = e;
        }
    }
    
    return ans;
}
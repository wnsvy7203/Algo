#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ans;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end());
    
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
        else
            now = min(now, target[1]);
    }
    
    return ans;
}
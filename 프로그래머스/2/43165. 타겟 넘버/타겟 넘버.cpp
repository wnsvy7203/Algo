#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(vector<int> nums, int l, int n)
{
    int ans = 0;
    
    queue<pair<int, int>> que;
    que.push({n, 0});
    
    while (!que.empty())
    {
        int f = que.front().first;
        int cnt = que.front().second;
        que.pop();
        
        if (cnt == l)
        {
            if (f == 0)
                ans++;
            continue;
        }
        
        int num = nums[nums.size()-1-cnt];
        
        que.push({f+num, cnt+1});
        que.push({f-num, cnt+1});
    }
    
    return ans;
}

int solution(vector<int> numbers, int target) {
    return bfs(numbers, numbers.size(), target);
}
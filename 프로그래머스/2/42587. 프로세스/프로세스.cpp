#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int>> que;

int solution(vector<int> priorities, int location) {
    for (int i = 0; i < priorities.size(); i++)
        que.push({priorities[i], i});
    
    int ans = 1;
    int cnt = 0;
    int len = que.size();

    while (!que.empty())
    {
        int MAX = *max_element(priorities.begin(), priorities.end());
        int prior = que.front().first;
        int idx = que.front().second;
        
        que.pop();
        if (prior == MAX)
        {
            priorities.erase(find(priorities.begin(), priorities.end(), MAX));

            if (idx == location)
                return ans;
            
            ans++;
            cnt++;
        }
        else
        {
            cnt++;
            if (cnt == len)
            {
                len--;
                cnt = 0;
            }
            
            que.push({prior, idx});
        }
    }
}
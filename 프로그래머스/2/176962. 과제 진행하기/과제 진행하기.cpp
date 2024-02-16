#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> answer;
stack<pair<string, int>> stk;
int now;

bool cmp (vector<string> a, vector<string> b)
{
    return a[1] < b[1];
}
vector<string> solution(vector<vector<string>> plans) {
    int N = plans.size();
    
    sort(plans.begin(), plans.end(), cmp);
    
    for (vector<string> plan : plans)
    {
        int start = stoi(plan[1].substr(0, 2)) * 60 + stoi(plan[1].substr(3, 2));
        
        while (now < start)
        {
            if (!stk.empty())
            {
                stk.top().second--;
                if (!stk.top().second)
                {
                    answer.push_back(stk.top().first);
                    stk.pop();
                }
            }
            now++;
        }
        
        stk.push({plan[0], stoi(plan[2])});
    }
    
    while (!stk.empty())
    {
        answer.push_back(stk.top().first);
        stk.pop();
    }
    
    return answer;
}
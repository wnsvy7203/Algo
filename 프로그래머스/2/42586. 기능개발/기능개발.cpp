#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> que;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
        vector<int> answer;
    for (int i = 0; i < progresses.size(); i++)
        que.push(i);
    
    while (!que.empty())
    {
        for (int i = 0; i < progresses.size(); i++)
            progresses[i] += speeds[i];
        
        int cnt = 0;
        if (progresses[que.front()] >= 100)
        {
            cnt++;
            int f = que.front();
            que.pop();
            for (int i = f+1; i < progresses.size(); i++)
                if (progresses[i] >= 100)
                {
                    cnt++;
                    que.pop();
                }
                else
                    break;
        }
        if (cnt)
            answer.push_back(cnt);   
    }
    return answer;
}
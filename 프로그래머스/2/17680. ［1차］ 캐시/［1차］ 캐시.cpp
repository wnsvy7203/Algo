#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if (!cacheSize)
        return cities.size() * 5;
    
    for (int i = 0; i < cities.size(); i++)
        for (int j = 0; j < cities[i].size(); j++)
            if (cities[i][j] >= 97 && cities[i][j] <= 122)
                cities[i][j] -= 32;
    
    deque<string> deq;
    for (string str : cities)
    {
        bool flag = 0;
        int idx = -1;
        
        for (int j = 0; j < deq.size(); j++)
        {
            if (deq[j] == str)
            {
                flag = 1;
                idx = j;
                break;
            }
        }
        
        if (flag)
        {
            answer++;
            string hit = deq[idx];
            deq.erase(deq.begin() + idx);
            deq.push_back(hit);
        }
        else
        {
            answer += 5;
            
            deq.push_back(str);
            if (deq.size() > cacheSize)
                deq.pop_front();
        }
    }

    return answer;
}
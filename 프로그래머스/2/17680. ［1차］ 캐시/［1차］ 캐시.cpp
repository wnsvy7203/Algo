#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    // 만약 캐시 크기가 0이라면 deque에 넣을 필요도 없이 5초씩 소요된다.
    if (!cacheSize)
        return cities.size() * 5;
    
    // 대소문자의 구분이 없다고 했으므로 모든 cities의 원소들을 대문자로 바꿔준다.
    for (int i = 0; i < cities.size(); i++)
        for (int j = 0; j < cities[i].size(); j++)
            if (cities[i][j] >= 97 && cities[i][j] <= 122)
                cities[i][j] -= 32;
    
    // deque 선언
    deque<string> deq;
    // cities의 원소들을 순회하면서 확인한다.
    for (string str : cities)
    {
        // 만약 
        auto it = find(deq.begin(), deq.end(), str);
        
        if (it != deq.end())
        {
            int idx = it - deq.begin();

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
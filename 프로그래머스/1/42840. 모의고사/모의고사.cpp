#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a = {1, 2, 3, 4, 5};
vector<int> b = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    int len = answers.size();
    
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i % 5] == answers[i])
            cnt1++;
        
        if (b[i % 8] == answers[i])
            cnt2++;
        
        if (c[i % 10] == answers[i])
            cnt3++;
    }
    
    vector<int> answer;
    int MAX = max({cnt1, cnt2, cnt3});
    if (MAX == cnt1)
        answer.push_back(1);
    if (MAX == cnt2)
        answer.push_back(2);
    if (MAX == cnt3)
        answer.push_back(3);
    
    sort(answer.begin(), answer.end());
    return answer;
}
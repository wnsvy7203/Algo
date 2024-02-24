#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int n = queue1.size();
    long long sum1 = 0, sum2 = 0;
    queue<int> q1, q2;
    for (int i = 0; i < n; i++)
    {
        sum1 += queue1[i];
        q1.push(queue1[i]);
        
        sum2 += queue2[i];
        q2.push(queue2[i]);
    }
    
    while (sum1 != sum2)
    {
        if (answer > n * 2 + 1)
            return -1;
        
        answer++;
        if (sum1 > sum2)
        {
            int num = q1.front();
            q2.push(num);
            sum2 += num;
            sum1 -= num;
            q1.pop();
        }
        else
        {
            int num = q2.front();
            q1.push(num);
            sum1 += num;
            sum2 -= num;
            q2.pop();
        }
    }
    
    return answer;
}
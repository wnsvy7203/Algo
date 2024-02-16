#include <string>
#include <vector>

using namespace std;

int answer;

vector<double> degree(int s)
{
    int h = s / 3600;
    s -= h * 3600;
    
    int m = s / 60;
    s -= m * 60;
    
    double d_hour = (h % 12) * 30.0 + m * 0.5 + s / 120.0;
    double d_minute = m * 6.0 + s * 0.1;
    double d_second = s * 6.0;
    
    return {d_hour, d_minute, d_second};
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2)
{
    int start = h1*3600 + m1*60 + s1;
    int end = h2*3600 + m2*60 + s2;
    
    vector<double> v1 = degree(start);
    if (v1[0] == v1[1] || v1[1] == v1[2] || v1[2] == v1[0])
        answer++;
    
    for (int now = start; now < end; now++)
    {
        vector<double> cur = degree(now);
        vector<double> next = degree(now+1);
        
        // 1. 초침과 시침이 겹친 경우
        if (cur[0] > cur[2] && next[0] <= next[2] && next[0] != next[1])
            answer++;
        else if (cur[0] > 354 && cur[2] == 354 && next[0] != next[1])
            answer++;    
        
        // 2. 초침과 분침이 겹친 경우
        if (cur[1] > cur[2] && next[1] <= next[2] && next[0] != next[1])
            answer++;
        else if (cur[1] > 354 && cur[2] == 354 && next[0] != next[1])
            answer++;
        
        // 3. 분침과 시침이 겹친 경우
        if (next[0] == next[1])
            answer++;
    }
    
    return answer;
}
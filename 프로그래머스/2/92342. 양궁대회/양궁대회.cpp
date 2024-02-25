#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// 이기기 위해서 얻어야 할 점수, 라이언 점수, 어피치 점수
vector<int> to_win(11), ryan(11), apeach(11), answer;

// 화살을 쏜 횟수
int arrow;

int MAX = -1;

void check()
{
    int score_ryan = 0, score_apeach = 0;
    for (int i = 0; i < 11; i++)
    {
        if (ryan[i] > apeach[i])
            score_ryan += 10 - i;
        else
        {
            if (!ryan[i] && !apeach[i])
                continue;
            else
                score_apeach += 10 - i;
        }
    }

    if (score_ryan <= score_apeach)
        return;
    
    if (MAX < score_ryan - score_apeach)
    {
        MAX = score_ryan - score_apeach;
        answer = ryan;
    }
    else if (MAX == score_ryan - score_apeach)
    {
        for (int i = 10; i >= 0; i--)
        {
            if (ryan[i] > answer[i])
            {
                answer = ryan;
                break;
            }
            else if (!ryan[i] && answer[i])
                break;
        }
    }
}

void dfs(int cnt, int depth, int arrow)
{
    if (cnt == arrow)
    {
        check();
        return;
    }
    
    int cur = arrow - cnt;
    if (depth == 10)
    {
        ryan[depth] = cur;
        dfs(cnt + cur, depth+1, arrow);
        ryan[depth] = 0;
    }
    else
    {
        if (to_win[depth] <= cur)
        {
            ryan[depth] = to_win[depth];
            dfs(cnt + to_win[depth], depth+1, arrow);
            ryan[depth] = 0;
        }
        
        dfs(cnt, depth+1, arrow);
    }
}

vector<int> solution(int n, vector<int> info) {
    apeach = info;
    for (int i = 0; i < 11; i++)
        to_win[i] = info[i] + 1;
    
    dfs(0, 0, n);

    if (MAX == -1)
        answer.push_back(-1);
    
    return answer;
}
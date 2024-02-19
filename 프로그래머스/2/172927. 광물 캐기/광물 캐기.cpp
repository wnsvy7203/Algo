#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer, idx;
int diamond, iron, stone, total;
vector<vector<int>> fatigue;

void init(vector<int> picks, vector<string> minerals)
{
    diamond = picks[0];
    iron = picks[1];
    stone = picks[2];
    total = diamond + iron + stone;
    
    while (idx < total)
    {
        int res = 0, res1 = 0, res2 = 0, res3 = 0;
        for (int i = idx*5; i < idx*5+5; i++)
        {
            if (i >= minerals.size())
                break;
            
            if (minerals[i] == "diamond")
            {
                res += 25;
                res1++;
            }
            else if (minerals[i] == "iron")
            {
                res += 5;
                res2++;
            }
            else
            {
                res++;
                res3++;
            }
        }
        
        idx++;
        fatigue.push_back({res, res1, res2, res3});
    }
    
    sort(fatigue.begin(), fatigue.end(), greater<>());
}

void settings()
{
    for (vector<int> v : fatigue)
    {
        if (diamond > 0)
        {
            diamond--;
            answer += v[1] + v[2] + v[3];
        }
        else if (iron > 0)
        {
            iron--;
            answer += v[1] * 5 + v[2] + v[3];
        }
        else if (stone > 0)
        {
            stone--;
            answer += v[1] * 25 + v[2] * 5 + v[3];
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    init(picks, minerals);
    settings();
    
    return answer;
}
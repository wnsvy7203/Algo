#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// idea: 완전탐색? n 100개 m 7개니까 가능하겠다.
// 4의 7승 = 16384 번 연산
// ...?

vector<vector<int>> ratio;

void perm_repetition(vector<int> v, vector<int> perm, int depth)
{
    if (depth == perm.size())
    {        
        ratio.push_back(perm);
        return;
    }
    
    for (int i = 0; i < v.size(); i++)
    {
        perm[depth] = v[i];
        perm_repetition(v, perm, depth+1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<vector<int>> answer;
    
    int m = emoticons.size();
    vector<int> v = {60, 70, 80, 90};
    vector<int> perm(m);
    
    perm_repetition(v, perm, 0);
    
    for (int i = 0; i < ratio.size(); i++)
    {
        vector<int> res(2, 0);
        for (vector<int> user : users)
        {
            int sum = 0;
            for (int j = 0; j < m; j++)
            {
                if (user[0] > 100 - ratio[i][j])
                    continue;
                
                sum += (ratio[i][j] * emoticons[j] / 100);
            }
            
            if (sum >= user[1])
                res[0]++;
            else
                res[1] += sum;
        }
        
        answer.push_back(res);
    }
    
    sort(answer.begin(), answer.end(), greater<>());
    
    return answer[0];
}
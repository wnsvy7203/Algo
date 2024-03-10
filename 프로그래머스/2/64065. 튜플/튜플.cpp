#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> v;
    for (int i = 1; i < s.size()-1; i++)
        if (s[i] == '{')
        {
            vector<int> tmp;
            string str = "";
            for (int j = i+1; j < s.size()-1; j++)
                if (s[j] == '}')
                {
                    tmp.push_back(stoi(str));
                    break;
                }
                else if (isdigit(s[j]))
                    str += s[j];
                else if (s[j] == ',')
                {
                    tmp.push_back(stoi(str));
                    str = "";
                }
            
            v.push_back(tmp);
        }
    
    sort(v.begin(), v.end(), cmp);
    
    for (vector<int> it : v)
        for (int num : it)
            if (find(answer.begin(), answer.end(), num) == answer.end())
                answer.push_back(num);
                
    return answer;
}
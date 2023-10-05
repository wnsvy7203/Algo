#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for (string s : quiz)
    {
        bool flag = 0;  // +는 0, -는 1
        int res = 0;
        int idx = 0;
        string tmp = "";
        for (int i = 0; i < s.size(); i++)
            if (isdigit(s[i]))
                tmp += s[i];
            else if (s[i] == ' ')
            {
                if (!tmp.empty())
                {
                    if (flag)
                    {
                        res -= stoi(tmp);
                        tmp = "";
                    }                        
                    else
                    {
                        res += stoi(tmp);
                        tmp = "";
                    }
                }
            }
            else if (s[i] == '-')
            {
                if (s[i-1] == ' ')
                    flag = !flag;
                else
                    tmp += s[i];
            }
            else if (s[i] == '+')
                flag = 0;
            else if (s[i] == '=')
            {
                idx = i+2;
                break;
            }
        
        string tmp2 = "";
        for (int i = idx; i < s.size(); i++)
            tmp2 += s[i];
        
        if (res == stoi(tmp2))
            answer.push_back("O");
        else
            answer.push_back("X");
    }

    return answer;
}
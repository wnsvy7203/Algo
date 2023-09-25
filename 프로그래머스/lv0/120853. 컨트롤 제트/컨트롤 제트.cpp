#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string tmp = "";
    int answer = 0;
    for (int i = 0; i < s.size(); i++)
        if (isdigit(s[i]) || s[i] == '-')
            tmp += s[i];
        else if (s[i] == ' ')
        {
            if (s[i+1] == 'Z')
                tmp = "";
            
            if (!tmp.empty())
            {
                answer += stoi(tmp);
                tmp = "";
            }
        }
    
    if (!tmp.empty())
        answer += stoi(tmp);

    return answer;
}
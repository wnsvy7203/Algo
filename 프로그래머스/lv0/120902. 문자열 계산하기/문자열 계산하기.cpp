#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    bool flag = 0;
    
    string tmp = "";
    for (char c : my_string)
        if (isdigit(c))
            tmp += c;
        else if (c == '+')
            flag = 0;
        else if (c == '-')
            flag = 1;
        else if (c == ' ')
        {
            if (!tmp.empty())
            {
                if (flag)
                    answer -= stoi(tmp);
                else
                    answer += stoi(tmp);
                
                tmp = "";
            }
        }
    
        if (!tmp.empty())
            if (flag)
                answer -= stoi(tmp);
            else
                answer += stoi(tmp);
    
    return answer;
}
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    string tmp = "";

    for (char c : my_string)
    {
        if (isdigit(c))
            tmp += c;
        else
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
#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    string tmp = "";
    for (int i = 0; i < my_str.size(); i++)
    {
        if (i && !(i % n))
        {
            answer.push_back(tmp);
            tmp = "";
        }
        
        tmp += my_str[i];
    }

    if (!tmp.empty())
        answer.push_back(tmp);

    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for (char c : my_string)
        if (answer.find(c) == string::npos)
            answer += c;
    return answer;
}
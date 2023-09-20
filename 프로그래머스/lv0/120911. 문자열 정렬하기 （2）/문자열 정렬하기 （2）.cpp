#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for (int i = 0; i < my_string.size(); i++)
        if (65 <= my_string[i] && my_string[i] <= 90)
            answer += my_string[i] + 32;
        else
            answer += my_string[i];
    sort(answer.begin(), answer.end());
    return answer;
}
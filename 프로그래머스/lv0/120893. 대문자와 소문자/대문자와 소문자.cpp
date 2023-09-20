#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for (char c : my_string)
        if (97 <= c && c <= 122)
            answer += c - 32;
        else answer += c + 32;
    return answer;
}
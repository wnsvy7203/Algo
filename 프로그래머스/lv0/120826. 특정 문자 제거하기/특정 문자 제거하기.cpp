#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    for (int i = 0; i < my_string.size(); i++)
        if (my_string[i] != *letter.c_str())
            answer += my_string[i];
    
    return answer;
}
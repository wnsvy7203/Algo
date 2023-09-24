#include <string>
#include <vector>

using namespace std;

int alphabet[26];

string solution(string s) {
    for (char c : s)
        alphabet[c-97]++;
    
    string answer = "";
    for (int i = 0; i < 26; i++)
        if (alphabet[i] == 1)
            answer += i+97;
    return answer;
}
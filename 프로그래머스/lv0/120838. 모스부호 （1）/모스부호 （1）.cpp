#include <string>
#include <vector>

using namespace std;

string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

string solution(string letter) {
    string tmp = "";
    string answer = "";
    for (char c : letter)
    {
        if (c == ' ')
        {
            for (int i = 0; i < 26; i++)
                if (morse[i] == tmp)
                    answer += i+97;
                    
            tmp = "";
        }
        else
            tmp += c;
            
    }
    
    for (int i = 0; i < 26; i++)
        if (morse[i] == tmp)
            answer += i+97;
    
    return answer;
}
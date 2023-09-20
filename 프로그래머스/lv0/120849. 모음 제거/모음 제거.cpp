#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for (auto i : my_string)
        if (i != 'a' && i != 'i' && i != 'o' && i != 'e' && i != 'u')
            answer += i;
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int len = str2.size();
    for (int i = 0; i < str1.size(); i++)
        if (str1[i] == str2[0] && str1.substr(i, len) == str2)
            return 1;
        
    return 2;
}
#include <string>
#include <vector>

using namespace std;

string s;

int solution(vector<int> array) {
    for (int i = 0; i < array.size(); i++)
        s += to_string(array[i]);
    
    int answer = 0;
    for (char c : s)
        if (c == '7')
            answer++;
    
    return answer;
}
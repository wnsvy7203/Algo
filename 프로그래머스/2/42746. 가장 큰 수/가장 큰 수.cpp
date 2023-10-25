#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b)
{    
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> v;
    for (int num : numbers)
        v.push_back(to_string(num));
    
    sort(v.begin(), v.end(), comp);
    string answer = "";
    
    for (string s : v)
        answer += s;
    
    if (answer[0] == '0')
        return "0";
    
    return answer;
}
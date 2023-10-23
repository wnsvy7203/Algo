#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> par;

string solution(vector<string> participant, vector<string> completion) {
    for (string str : participant)
        par[str]++;
    
    for (string str : completion)
        par[str]--;
    
    string answer = "";
    for (auto iter = par.begin(); iter != par.end(); iter++)
        if (iter -> second > 0)
            answer = iter -> first;
    
    return answer;
}
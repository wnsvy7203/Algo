#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> clo;

int solution(vector<vector<string>> clothes) {
    for (vector<string> tmp : clothes)
        clo[tmp[1]]++;
    
    int answer = 1;

    for (auto iter = clo.begin(); iter != clo.end(); iter++)
        answer *= iter -> second+1;
    
    return answer - 1;
}
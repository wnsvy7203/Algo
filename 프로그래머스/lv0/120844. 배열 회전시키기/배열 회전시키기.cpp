#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    if (direction == "left")
    {
        for (int i = 1; i < numbers.size(); i++)
            answer.push_back(numbers[i]);
        
        answer.push_back(numbers[0]);
    }
    else
    {
        answer.push_back(numbers[numbers.size()-1]);
        
        for (int i = 0; i < numbers.size()-1; i++)
            answer.push_back(numbers[i]);
    }
        
    return answer;
}
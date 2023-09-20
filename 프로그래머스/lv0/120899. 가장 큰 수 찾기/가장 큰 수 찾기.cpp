#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    int ans1 = 0, ans2 = 0;
    
    for (int i = 0; i < array.size(); i++)
        if (ans1 < array[i])
        {
            ans1 = array[i];
            ans2 = i;
        }
    
    answer.push_back(ans1);
    answer.push_back(ans2);
    return answer;
}
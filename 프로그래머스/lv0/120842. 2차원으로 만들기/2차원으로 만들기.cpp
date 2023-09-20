#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    int s = 0;
    while (s < num_list.size())
    {
        vector<int> tmp;
        for (int i = s; i < s+n; i++)
            tmp.push_back(num_list[i]);
        
        answer.push_back(tmp);
        s += n;
    }
        
    return answer;
}
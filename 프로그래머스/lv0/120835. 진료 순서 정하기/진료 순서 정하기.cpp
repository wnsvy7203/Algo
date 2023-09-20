#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> v;
    for (int i : emergency)
        v.push_back(i);
    
    sort(v.begin(), v.end(), greater<>());
    vector<int> answer;
    int ans = 1;
    for (int i : emergency)
        for (int j = 0; j < v.size(); j++)
            if (i == v[j])
                answer.push_back(j+1);

    return answer;
}
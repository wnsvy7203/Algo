#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int len = numbers.size();
    vector<int> v(len-2, 0);
    v.push_back(1);
    v.push_back(1);
    int answer = -100000000;
    do
    {
        int tmp = 1;
        for (int i = 0; i < len; i++)
            if (v[i])
                tmp *= numbers[i];
        
        answer = max(answer, tmp);
    } while (next_permutation(v.begin(), v.end()));
    return answer;
}
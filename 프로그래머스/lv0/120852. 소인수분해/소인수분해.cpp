#include <string>
#include <vector>

using namespace std;

bool nums[10001];

void tera()
{
    for (int i = 2; i < 10001; i++)
        if (!nums[i])
            for (int j = i*2; j < 10001; j += i)
                nums[j] = 1;
}

vector<int> solution(int n) {
    tera();
    vector<int> answer;
    for (int i = 2; i <= n; i++)
        if (!nums[i] && !(n % i))
            answer.push_back(i);
    return answer;
}
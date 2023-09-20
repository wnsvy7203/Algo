#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
    for (int k : array)
        if (k > height)
            answer++;
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    while (order)
    {
        int check = order % 10;
        if (check && !(check % 3))
            answer++;
        order /= 10;
    }
    return answer;
}
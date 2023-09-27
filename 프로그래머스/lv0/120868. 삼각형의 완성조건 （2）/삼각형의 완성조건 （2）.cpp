#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    sort(sides.begin(), sides.end());
    int answer = 0;
    for (int i = 1; i <= sides[1]; i++)
        if (sides[0] + i > sides[1])
            answer++;
    
    for (int i = sides[1]+1; i < sides[0] + sides[1]; i++)
        if (sides[0] + sides[1] > i)
            answer++;
    
    return answer;
}
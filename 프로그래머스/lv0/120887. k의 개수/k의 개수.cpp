#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    for (int x = i; x <= j; x++)
        for (char c : to_string(x))
            if (c == k + 48)
                answer++;
    return answer;
}
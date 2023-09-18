#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    while (1)
        if (!(n % 7))
            return n / 7;
        else
            n++;
}
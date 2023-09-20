#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    return (int)sqrt(n)*int(sqrt(n)) == n ? 1 : 2;
}
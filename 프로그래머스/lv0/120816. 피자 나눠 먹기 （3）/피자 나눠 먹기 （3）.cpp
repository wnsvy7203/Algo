#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    if (n % slice)
        return n / slice + 1;
    else
        return n / slice;
}